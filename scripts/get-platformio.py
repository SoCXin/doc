 

import tempfile
import io
import sys
import subprocess

MAIN_SCRIPT_URL = "https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py"


def download_with_requests(url, dst):
    import requests

    resp = requests.get(url, stream=True)
    itercontent = resp.iter_content(chunk_size=io.DEFAULT_BUFFER_SIZE)
    with open(dst, "wb") as fp:
        for chunk in itercontent:
            fp.write(chunk)
    return dst


def download_with_urllib3(url, dst):
    import urllib3

    http = urllib3.PoolManager()
    r = http.request("GET", url, preload_content=False)

    with open(dst, "wb") as out:
        while True:
            data = r.read(io.DEFAULT_BUFFER_SIZE)
            if not data:
                break
            out.write(data)

    r.release_conn()
    return dst


def download_with_urllib(url, dst):
    if sys.version_info[0] == 3:
        from urllib.request import urlopen
    else:
        from urllib import urlopen

    response = urlopen(url)
    CHUNK = 16 * 1024
    with open(dst, "wb") as f:
        while True:
            chunk = response.read(CHUNK)
            if not chunk:
                break
            f.write(chunk)

    return dst


def download_with_curl(url, dst):
    subprocess.check_output(["curl", "-o", dst, url])
    return dst


def download_with_wget(url, dst):
    subprocess.check_output(["wget", "-O", dst, url])
    return dst


def download_file(url, dst):
    methods = [
        download_with_requests,
        download_with_urllib3,
        download_with_urllib,
        download_with_curl,
        download_with_wget,
    ]
    for method in methods:
        try:
            method(url, dst)
            return dst
        except:
            pass
    raise Exception("Could not download file '%s' to '%s' " % (url, dst))


def main():
    with tempfile.NamedTemporaryFile() as tmp_file:
        dst = download_file(MAIN_SCRIPT_URL, str(tmp_file.name))
        command = [sys.executable, dst]
        command.extend(sys.argv[1:])
        subprocess.check_call(command)


if __name__ == "__main__":
    sys.exit(main())
