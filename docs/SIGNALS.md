# SIGNALS AND PIPES
In Unix, signals are an essential part in the communication and concurrent execution of processes.

Page 53 for signal list

## Pipes
Pipes are logical devices that allow the communication among processes that have a familiar relationship.

## System calls related to commucation and sync inbetween processes
* pipe: creates a pipe in between the file descriptors of read/write
* signal: determines the action that handles a specific signal
* kill: sends a signal to a process or group of processes
* alarm: programs the clock of the process to send a SIGALRM
* pause: blocks the process until a signal arrives