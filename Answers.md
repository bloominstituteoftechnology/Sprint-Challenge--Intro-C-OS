What are some of the tasks that a general operating system is responsible for handling?

Describe in as much detail as you can _how_ these tasks are handled by the operating system.

The operating system behaves like a mediator between the user interface and the system hardware(cpu, ram, keyboard, whatever). It hides the complexities behind the complicated hardware. One of these complications is Processor Management, the OS has to make sure that each process and application recieves enough of the processor's time to function properly.

In short, it accepts input, manages the hardware resources (like memory, disk space, etc)), and then displays the output. additionally, os provides a consistent way for applications to deal with hardware without knowing every single detail about the hardware. it allows a developer to have a high amount of confidence that their program will work on other computers, even if some of the hardware is different.
