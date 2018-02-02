# Sprint-Challenge: Intro to C and Operating Systems

Complete both challenges, below.

_The Challenge 2 code needs a Unix-like environment to work! That includes
Linux, macos, MinGW, Cygwin, WSL, BSD, etc._

If you want to test if your environment is set up for it, compile and
run the [testdir.c](examples/testdir.c) program in the `examples/`
directory. It should print `Testing: PASS`.

## Challenge 1

What are some of the tasks that a general operating system is responsible for handling?

An operating system is a program which controls the execution of all other programs or applications. It acts as an intermediary between the users and computers. An operating system's objectives include convenience, efficiency, and extensibility. An operating system is responsible for managing the entire computer system. It has many different functions, which are all important for the overall operation of the computer. They include providing a user interface, management of the memory, peripheral management, multi-tasking, and security.


Describe in as much detail as you can _how_ these tasks are handled by the operating system. 

_User interfaces_
Communication between a user and a computer is two-way. We know that one of the jobs of the operating system is to provide a 'user interface', so that a human can communicate with the hardware that makes up a computer. When you buy a piece of software, it too will have a user interface, so that you can access and use the software. A user will give data and instructions to a computer and a computer will give information back to a user. The way that a computer and a user communicate is known as the 'interface'. There are alternative terms to describe this. Another common term is the 'Human-Computer Interface' (HCI).

_Memory management_
When you access a piece of software (or a file), the operating system goes to the hard drive, finds it and then copies it into RAM where the CPU can then access it. The operating system has to find somewhere in RAM that isn't being used by anything else when it copies it from the hard drive. If it just put the program into RAM anywhere it liked, it might overwrite existing valuable files or another program and most likely cause the computer to crash.
To prevent this, the operating system manages the memory. It keeps track of what software applications and files are open and where it has put them in RAM. It also keeps track of where there are free areas, areas which it can use. When you want to open a new application, it finds a suitable free area and copies it to that area. It then updates its own records to show that that area of RAM is now taken.

_Peripheral management_
An operating system is also responsible for managing the peripherals. A peripheral is anything that can be connected to the CPU, although you would normally connect a peripheral by plugging it in to a port, and then the port is connected inside the computer's box to the CPU. Common peripherals include mice, monitors, web cams, scanners, cameras, graphics tablets, printers and so on. When you plug a peripheral into a computer, the computer will first of all check to see if it has the right kind of software to run that peripheral. These are known as 'drivers' because they drive the peripheral and make it work. If the operating system can detect the peripheral and the driver to run it, it will give you a message that it is ready to be used. If it can't set it up correctly, then the operating system will give you an error message and perhaps some advice about solving the problem. Once the device is working, you can adjust settings in the peripheral's dedicated software or via the operating system. For example, you could change the resolution of the monitor or the speed that your mouse recognises clicks.

_Multi-tasking_
CPUs can only work on one instruction from one program at a time, but they can do this at billions of instructions a second. If it wants to work on 5 programs at the same time, how does it do it? The answer is very simple. It spends a short time (billionths of a second) on the first program. It then stops, saves its' current state to memory and then gets the settings for the second program and works on that for a few billionths of a second. Then it saves where its' current state and moves on to the settings for the next program and so on. It gives each application a little bit of CPU time before moving on to the next application and then goes back to the first application and repeats, but it does this so quickly that we think that applications are running at the same time. This is known as 'multi-tasking'.
The operating system is responsible for organising multi-tasking. It is the operating system that decides the order that different software applications will be worked on by the CPU, which one the processor work on now and when to stop that job and give it the next one.

_Security_
Operating systems are responsible for the security of a computer system. This is accomplished by leveraging three general concepts. Software updates, Firewalls, and Account management.

Software updates. Operating systems are responsible for making sure that any software updates are downloaded and installed. People are constantly finding problems and flaws with software and sometimes criminals will exploit these. As problems are discovered, solutions are created and distributed to operating system in an attempt to mitigate these exploits.

Firewalls. Operating systems often have a basic firewall that can be used to stop people from gaining unauthorized access to a computer in a network, although you can also buy commercial firewalls that have more features.

Account management. Often, more than one person has access to a single computer on a network, there could be thousands of people who have access to a network's data. An operating system is responsible for setting up accounts for each person who might need legitimate access to a computer or network with a login and password and to prevent unauthorized access to network traffic and resources.

## Challenge 2

Write a program in C, `lsls.c`, that prints out a directory listing for the
directory the user specifies on the command line. If the user does not specify a
directory, print out the contents of the current directory, which is called `.`.

Example runs:

```
$ ./lsls
.
..
lsls.c
lsls

$ ./lsls /home/exampleuser
.
..
.config
.vim
.yarnrc
.bashrc
foo.c
.vscode
Downloads
.gitconfig
.bash_history
.viminfo
src
```

To parse the command line, you'll have to look at `argc` and `argv` specified in
your `int main(int argc, char **argv)`. Example code to print all command line
arguments can be found in [commandline.c](examples/commandline.c).

General approach: Call `opendir()`, then repeatedly call `readdir()`--printing
the filenames as you go--until it says there are no more entries, then call
`closedir()`

You will be using functionality included in `<dirent.h>`. This header file holds
the declarations for `DIR`, `struct dirent`, `opendir()`, `readdir()`, and
`closedir()`, below.

* `DIR *opendir(char *path)`: This function opens the directory named in `path`
  and returns a pointer to a variable of type `DIR` that will be used later. If
  there is an error, `opendir()` returns `NULL`.

* `struct dirent *readdir(DIR *d)`: Reads the next directory entry from the
  `DIR` returned by `opendir()`. Returns the result as a pointer to a `struct
  dirent` (see below). Returns `NULL` if there are no more directory entires.

* `closedir(DIR *d)`: Close a directory (opened previously with `opendir()`)
  when you're done with it.

The `struct dirent *` returned by `readdir()` has the following fields in it:

```c
struct dirent {
  ino_t  d_ino       // file serial number
  char   d_name[]    // file name, a string
};
```

For output, you should print the field `d_name`.

### Stretch Goal: Print file size in bytes

Modify the program to print out the file size in bytes as well as the name.

Example output (suggestion: use `%10lld` to print the size in a
field of width 10):

```
$ ./lsls
    224  .
    992  ..
   1722  lsls.c
   8952  lsls
```

You'll need to use the `stat()` call in `<sys/stat.h>`.

* `int stat(char *fullpath, struct stat *buf)`: For a given full path to a file
  (i.e. the path passed to `opendir()` following by a `/` followed by the name
  of the file in `d_name`), fill the fields of a `struct stat` that you've
  pointed to. Returns `-1` on error.

  ```c
  // Example stat() usage

  struct stat buf;

  stat("./lsls.c", &buf);

  printf("file size is %lld\n", buf.st_size);
  ```

### Stretch Goal: Mark Directories

Instead of a size in bytes for a directory, replace the number with
the string `<DIR>`.

Example output:

```
$ ./lsls
     <DIR>  .
     <DIR>  ..
      1717  lsls.c
      8952  lsls
```

The `st_mode` field in the `struct stat` buffer holds information
about the file permissions and type of file.

If you bitwise-AND the value with `S_IFDIR` and get a non-zero
result, the file is a directory.

(If you bitwise-AND the value with `S_IFREG` and get a non-zero
result, the file is a regular file, as opposed to a device node,
symbolic link, hard link, directory, named pipe, etc.)
