The operating system is the gate keeper between the user space and the kernel space.

1) It is responsible to keep non-privleged processes from wrecking havoc to the kernel and killing the process if necessary. The pro is the extra security but the con is it takes longer to make system calls. The operating system is like a server, the user space processes can make `requests` and says hey, operating system can you do something for me, then the operating system can `respond` back with the desired response or just deny the processe's request.

2) Another responsibility for the OS is the scheduling of what process should run when and stopping a process when necessary, also known as scheduling. This is how it prioritizes what process needs to run first and which ones are secondary.

3) It can try to talk to other devices that you connect to your computer such as a USB which should have a driver for the communication process to happen between the device and OS.