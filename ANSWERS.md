## Challenge 1:

Q: What are some of the tasks that general operating system is responsible for handling?

Describe in as much detail as you can _how_ these tasks are handled by the operating system.

A: Managing communication between hardware and software. Allocating memory. Allocating CPU time. And organizing data on storage devices (HDD/SSD).


An OS manages communication between SW and HW by the use of interrupts such as for keyboards and mice. Or to display video on a monitor. Or when a software app is requested by the user the OS manages the finding of where that app is in HW and loading it up into memory for the user to use.

Memory allocation is handled by the OS for all software apps including the OS itself. This dynamic allocation of memory is used when an app is launched and the amount of memory needed by the app is adjusted/allocated as needed. When the app is closed the OS frees the memory used and performs garbage collection.

Multitasking wouldn't be possible on a computer if it wasn't for the OS performing context switching. This can be achieved by the OS using timers and interrupts that cause the CPU to switch which task it's currently working on. For example, perhaps you have MS Word running but the OS needs to run certain background tasks then the OS will use timers to cause an interrupt to tell the CPU to work on the OS's task briefly. But it happens so fast that you never notice anything as you continue working on your Word document.

Organizing data is performed by the OS whenever the OS loads, when an app needs to be loaded or have files saved, or when a user reads and writes files. The OS is not only responsible for the type of file system used (e.g.- NTFS or ext4), but is also responsible for sending and retrieving the data from storage devices.