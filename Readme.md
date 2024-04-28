

# Pipe replication


This program copies the work of the pipe ( | ), one of the forms of inter-process communication (IPC).


The program was written as part of a [42 programming school](https://42.fr/en/homepage/) project, 
in particular [42 Abu Dhabi school](https://42abudhabi.ae/).


## Description


The program assumes the same execution as the following shell code:


```shell
< file1 cmd1 | cmd2 > file2
```


## How to compile
```C
make all
./pipex infile cmd1 cmd2 outfile

```
The first and last parameters are files. The first one is from where to read the information (infile) and the last one is where to write the result (outfile).


`This compilation expects only one pipe.`


If you want to use two or more pipes please go down the page to the [Multiple pipes]("#multiple-pipes")


Please use double quotes " " if you are going to put commands with arguments.


Example: 
```shell
make all
```
```C
./pipex file1 "grep a" "wc -l" file2
```
Before the compilation please write something into infile, and after the execution you'll see the result inside the outfile. 

## Multiple pipes


This part of the program can handle more than 1 pipe as well.
To do so, please:


```shell
make re && make bonus
```
```C
./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile
```


It assumes to work as shell:
```shell
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
## Functions and code
This program is written in C programming language. 
To store the information about variables (commands in this case) I used `structers`. 
To implement the behavior of pipe, there were used functions like:


For processing files and file descriptors:
* access() with different argument like F_OK and X_OK
* open()
* close()


To create child processes and execute the commands
* pipe()
* fork()
* dup2()
* execve()
* wait()


Some regular functions as:
* malloc()
* free ()
* exit ()


As this program was written in C, the low-level programming language, I had to allocate and free memory to some necessary variables manually.


## Explanation of my implementation
The `main` function is placed in `pipex.c` file inside the `mandatory` folder.


The logic of my code is pretty simple and you can easily find it coded in `pipex.c`, `main_process()` function.
1) Create a linked list (and allocate memory for it) of commands with all necessary information (like the name of the command, the arguments, the path to the command, a file descriptor (if needed)).
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
Certainly, I free all allocated memory. I assume that I do not have memory leaks, but If you've found some, please let me know. 


## Review

This project was challenging and fascinating. I learned a lot about:
* pipes
* redirections
* file descriptors
* processes
* UNIX system
and liked it so much. 

Thanks for reading this README. I wish you the best of luck in the way of learning programming 🍀