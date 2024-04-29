

# Pipe replication


The program copies the work of the pipe operator (' | '). It allows users to execute a sequence of commands, with the output of one command serving as the input to the next command, similar to how pipes work in Unix-like operating systems.

The program was written as part of a [42 programming school](https://42.fr/en/homepage/) project, 
in particular [42 Abu Dhabi school](https://42abudhabi.ae/).


## Table of Contents
- [Installation && How to compile](#installation-&&-how-to-compile)
- [Multiple pipes](#multiple-pipes)
- [Functions](#functions)
- [Explanation of my implementation](#explanation-of-my-implementation)
- [Conclusion](#conclusion)


## Installation && How to compile
```bash
git clone https://github.com/sabdulki/pipex.git
```
```bash
cd pipex
```
```bash
./pipex infile cmd1 cmd2 outfile
```
Before the compilation please write something into infile, and after the execution you'll see the result inside the outfile. 

Please use double quotes " " if you are going to put commands with arguments.

Example: 
```bash
./pipex infile "grep a" "wc -l" outfile
```

The program assumes the same execution as the following shell code:
```shell
< file1 cmd1 | cmd2 > file2
```

Please note: `This compilation expects only one pipe.`

If you want to use two or more pipes please see below.  [Multiple pipes]("#multiple-pipes")

<!-- If you do not have `cc/gcc` compiler, please install it on you PC using command-line interface like Terminal to run the project. 

### Windows:
On Windows, you can install gcc using MinGW (Minimalist GNU for Windows) or MSYS2 (Minimal System 2):

* **MinGW**:
You can download the MinGW installer from the MinGW website: MinGW
* **MSYS2**:
Download and install MSYS2 from the MSYS2 website: MSYS2
After installing MinGW or MSYS2, you can use their package managers (pacman for MSYS2 or mingw-get for MinGW) to install gcc.

Once installed, you can verify the installation by running gcc --version in your terminal/command prompt. If gcc is installed correctly, it will display the version information.

### Linux:
On most Linux distributions, `gcc`` can be installed using the package manager:

* **Ubuntu/Debian**:
```bash
sudo apt update
sudo apt install gcc
```
* **CentOS/RHEL**:
```bash
sudo yum install gcc
```

### macOS
On macOS, you can install gcc using Homebrew, a popular package manager:

1) Install Homebrew (if you haven't already):
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
2) Install gcc:
```bash
brew install gcc
``` -->


## Multiple pipes

This part of the program can handle more than 1 pipe as well.
To do so, please:

```shell
make re && make bonus
```
```C
./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile
```

Example:
```C
./pipex infile "cat" "grep 1" "wc -l" "wc -w" outfile
```
It assumes to work as shell:
```shell
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```


## Functions
This program is written in C programming language. 
To implement the behavior of pipe, there were used some functions like:

For processing files and file descriptors:
* access() with different argument like F_OK and X_OK - to check if the programm has acces to the file and if it is executable.
* open() - to open the file and get it's file descriptor.
* close() - to close the file.

To create child processes and execute the commands
* pipe() - to create an unnamed pipe, which is a one-way communication channel that allows communication between a parent process and its child process.
* fork() - to create a child process.
* dup2() - to duplicate an open file descriptor to another file descriptor number. It's commonly used to redirect input and output. 
* execve() -  used to execute a program in the current process. Usually called in child process. 
* wait() -  allows the parent process to wait for the completion of its child processes before continuing its execution.

Some regular functions as:
* malloc() - to dynamicly allocate the memory.
* free () - to free the memeory tht was allocated using malloc().
* exit () -  to terminate the program execution and return a status code to the operating system


## Explanation of my implementation

The logic of my code is pretty simple and you can easily find it coded in `main` function inside the `mandatory` folder, `pipex.c` file.
1) Create a linked list of commands (and allocate memory for it)  with all necessary information (like the name of the command, the arguments, the path to the command, a file descriptor (if needed)).
```C
init_all_cmds();
```
2) Create all the pipes between the commands. I build the "connections" between them and store these relationships in them.
How does it work?
I create a pipe calling pipe() and store the reading end of the pipe in the first cmd, and the writing end of pipe in the second cmd. Thus, I could build the connections and get all the needed information (f.e. the result of execution of the cmd) without difficult manipulations.
```C
create_all_pipes();
```
3) Create the child processes and execute the commands submitted as arguments. After the execution, I wait for any command to be executed and check whether all the commands were executed successfully.
```C
execute_all_cmds();
wait_cmds();
```
I assume that I do not have memory leaks, but If you've found some, please let me know. 


## Conclusion

This project was challenging and fascinating. I learned a lot about:
* pipes
* redirections
* file descriptors
* processes
* UNIX system
and liked it so much. 

Thanks for reading this README. I hope you have founud it useful :slightly_smiling_face: