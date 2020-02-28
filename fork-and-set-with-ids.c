#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


// error handler
void error(char *m) {
	write(2, m, strlen(m));
	write(2, "\n", 1);
	write(2, strerror(errno), strlen(strerror(errno)));
	exit(1);
}

int main() {
	int st, pid;
	char s[80];

	switch (fork()) {

		case -1:
			error("Fork");

		case 0:
			// child process will run ls, attention to parameters
			execlp("ls", "ls", "-l", "/usr/bin", (char *)0);
			// if we reach chere, there is an error
			error("Executant ls");
		default:
			// parent process waits till child is done
			wait(&st);
			exit(0);

	}
}