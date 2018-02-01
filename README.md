# Sprint-Challenge: Intro to C and Operating Systems

Complete both challenges, below.

_The Challenge 2 code needs a Unix-like environment to work! That includes
Linux, macos, MinGW, Cygwin, WSL, BSD, etc._

If you want to test if your environment is set up for it, compile and
run the [testdir.c](examples/testdir.c) program in the `examples/`
directory. It should print `Testing: PASS`.

## Challenge 1

What are some of the tasks that a general operating system is responsible for handling?

*General operating systems are designed to manage the computer hardware and software resources.  Some of the tasks the genreal operating system does is managing communications between software and hardware, allocation of computer memory and allocation of CPU time*

Describe in as much detail as you can _how_ these tasks are handled by the operating system. 

*To elaborate on the tasks handled by the operating system listed above, please see below*
  
  1. Managing communications between software and hardware - 
      
      *i. Loading and saving data and programs*

      *ii. Communicating with hardwares such as mouse and printer*

      *iii. Displaying information in output form.*

  2. Allocation of computer memory - 
      
      *The Computer memory must be allocated across different tasks that is to be performed at any time.  Using a spreadsheet program as an example, memory would be required to open the software, to open a new spreadsheet document to be edited as well as to be shown on the monitor* 

  3. Allocation of CPU time - 

      *On most computers, there is only one microprocessor in the Central Processing Unit (CPU).  How it works is that it can only process one piece of data at one time.  With the task required to keep the operating system running, the time required from the CPU is divided and being carried out.  For example, moving the mouse cursor across the screen, opening a word document from a folder and keeping the monitor updated to show the actions being done by the user/computer*

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
