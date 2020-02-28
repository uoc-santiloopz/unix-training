# PROCESSES


In Unix there is a hierarchy of processes ruled by an initial process, from which all the processes are generated, this process, the `init` process, has a `pid` of 1 and is of vital importance in the system lifecycle.

## Important info about a process
* Process ID -> PID
* parent process ID
* process group ID
* user id -> UID
* user group id -> GID
* State of the process

## Lifecycle of a process
When we `fork` a process in Unix, this process has exactly the same characteristics as the parent process from which we have forked it, but since que normally want the child process to do very different tasks, we will `transform` this process with the help of the `exec` command.