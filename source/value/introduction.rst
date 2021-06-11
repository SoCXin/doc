经济价值
==================

What is PicoRio
----------------
PicoRio is an open-source project stewarded by the `RISC-V International Open Source (RIOS) laboratory`_, a nonprofit research lab at Tsinghua-Berkeley Shenzhen Institute (TBSI). The RIOS Lab uses collaborative engineering from both academia and industry to elevate the RISC-V software and hardware ecosystem. In PicoRio, we create an open, affordable, Linux-capable RISC-V hardware platform to aid software developers in porting many modern programs that require Javascript or GPUs. PicoRio will build upon high-quality IPs and software components from expert industry engineers and academic researchers. PicoRio is not proprietary to any specific vendor and platform, and will have complete documentation that can help people to build quality products in a short amount of time.

.. _RISC-V International Open Source (RIOS) laboratory: http://rioslab.org

Motivation
----------

Need more than processors to build a system
  * Large cost to license other IPs in SoC: cache, interconnect, graphics, camera ISP, etc.
  * Need an attractive open-source platform to try new hardware ideas.
  * Security and trusted execution are not complete without a full-system support.
  * RISC-V hardware extensions: JIT runtime, vector, etc.

The community lacks affordable RISC-V hardware platforms that run a variety of software
  * Few low-cost, software-capable boards for the long tail of developers.
  * Developers won’t spend $1000 for a new hardware just for software development.


Highlights
----------------

* **Independently Maintained**: The RIOS Lab will be the solo nonprofit organization that governs the architecture development, ensures compliance, and will publish the design. The RIOS Lab will be the gatekeeper for both hardware and software, from SoC and firmware/drivers to high-level software and documentation. PicoRio will be vendor agnostic and not proprietary, and the RIOS Lab will work with academic and commercial organizations that will commit to its expansion and volume manufacturing.

* **Open Source**: PicoRio will open source as many components as possible, including the CPU and main SoC design, chip package and board design files, device drivers, and firmware. The exceptions are foundry related IPs (e.g., TSMC SRAM configurations), commercial high-speed interfaces, and complex commercial IP blocks like GPU. Nevertheless, our goal is to reduce the commercial closed source IPs for each successive release of PicoRio, with the long term goal of having a version that is as open as practical.

* **High-Quality IPs**: A major goal of the RIOS Lab is to develop open-source, industrial strength hardware IPs to help the RISC-V ecosystem catch up with those of the older, proprietary ISAs. Thus, PicoRio aims at a high-quality silicon release using open-source IP. The IPs will have gone through rigorous real tapeout verifications that meet industry quality. The openness of PicoRio will not come at the cost of lower quality IP blocks. In addition, we will open source our verification process, which will help to improve transparency and trustworthiness.

* **Modern Software Stack Support**: PicoRio utilizes a heterogeneous multicore architecture and is Linux-capable. We also designed PicoRio hardware to run modern managed languages such as JavaScript/WebAssembly as well as graphical applications like the Chrome web browser. At the RIOS Lab, PicoRio is also the hardware platform for several other open-source software projects, like the RISC-V ports for the V8 Javascript engine and the Chromium OS.

* **Low-Power and Low-Cost**: The target metrics of PicoRio are long battery life and low cost, which is a better match to RISC-V today, instead of high performance and large memory.


