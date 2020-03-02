# DEVICES

In Unix based OSs, every device is represented through a file named `file descriptor`, which occupies a channel in the I/O estrategy of the OS. By consensus:
* 0 channel is the stdin
* 1 channel is the stout
* 2 channel is the stderr

## Devices and processes
The table of open channels is inherited exactly from parent to child processes, also the pointer position to where we have arrived reading a file.

## I/O system calls
* creat: creates a new file
* open: opens  a file
* close: closes a file descriptor or channel
* read: reads from a file
* write: writes in a file
* lseek: positions the read/write pointer
* dup: duplicate opened channel
* unlink: removes an entry (link) from the directory 