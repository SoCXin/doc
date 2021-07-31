lint:
	pylint -j 6 --rcfile=./.pylintrc ./tests

isort:
	isort ./tests

format:
	black --target-version py27 ./tests

before-commit: isort format lint

clean-docs:
	rm -rf docs/_build

clean: clean-docs
	find . -name \*.pyc -delete
	find . -name __pycache__ -delete
	rm -rf .cache
	rm -rf build
	rm -rf htmlcov
	rm -f .coverage

profile:
	# Usage $ > make PIOARGS="boards" profile
	python -m cProfile -o .tox/.tmp/cprofile.prof -m platformio ${PIOARGS}
	snakeviz .tox/.tmp/cprofile.prof

pack:
	python setup.py sdist

publish:
	python setup.py sdist upload
