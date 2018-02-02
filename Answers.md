What are some of the tasks that a general operating system is responsible for handling?

Describe in as much detail as you can _how_ these tasks are handled by the operating system. 

1. Operating Systems - Processes - Every operating system provides processes which are applications that run in user space. Process run in their own address space which means that variables in one processes are not visible to other process unless both explicity agree to communicate. 

2. Threads - Thread ares processed that do share address space. A single process will often spawn a number of threads to handle tasks with each thread having access to all the variables in the process.

3. Scheduling. Computers that has 4 cores can only run 4 programs at once but can handle hundreds of processes because the kernel switches which process gets run and gets switch into and out of core. Whenver a process is paused, the entire execution state is saved into main memory before the next process is loaded from main memory and execution is resumed. 

5. Memory : Operating system is responsible for providing user programs access to meory by creating stack frame when program begins to execute and allocates a section of free memory for program to use. One vulnerability is that if a process is able to gain access to more memory than what it has been assigned to it, it can hijack the system. The program should have no knowledge of any memory than what has been allocated by the operating system. 

6. Drivers: Drivers combine multiple languages including assembly, C, and intterupt driven programming to provide software control to hardware devices. It hides the detailsof communication from hardware to software developers. Hardware is built with PCIx bus controller and all drivers are written to control hardware on the other side of the PCIx bus.