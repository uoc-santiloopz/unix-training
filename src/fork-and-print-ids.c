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
			sprintf(s, "I am the child process %d\n", getpid());
			write(1, s, strlen(s));
			sprintf(s, "My parent process is %d\n", getppid());
			write(1, s, strlen(s));
			exit(0);

		default:
			sprintf(s, "I am the parent process %d\n", getpid());
			write(1, s, strlen(s));
			pid = wait(&st);
			sprintf(s, "My child finished process is %d\n", pid);
			write(1, s, strlen(s));
			exit(0);

	}
}