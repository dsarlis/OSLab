# OSLab
Operating Systems Laboratory assignments

## Overview
Assignments for Operating Systems Laboratory class at NTUA. Linux kernel driver development, QEMU development, virtualization techniques.

### Lab1
Implementation of a Linux kernel driver for a wireless sensor network. This network contains a number of voltage, temperature and light sensors. Developed a character device driver which takes input from the sensor network and exposes the information to userspace in different device files for each metric. The driver was developed as a Linux kernel module in virtual machines.

### Lab2
Developed virtual hardware for QEMU-KVM framework. Designed and implemented a virtual VirtIO cryptographic device as part of QEMU. The device allows applications running inside the VM to access the real host crypto device using paravirtualization. The device was implemented using the split-driver model: a frontend (inside the VM) and a backend (part of QEMU). The frontend exposes to user space applications the same API as the host cryptodev while the backend receives calls from the frontend and forwards them for processing by the host cryptodev. To test the driver's functionality, an ecrypted chat application over TCP/IP sockets was implemented.

### Lab3
A riddle game containing several challenges. Challenges included proper use of system calls, opening the correct files, listening to ports, creating child processes, etc to help the riddle executable run without errors.

## Requirements
* CPU virtualization extensions
* KVM module loaded into kernel
* QEMU >= 1.2.1
