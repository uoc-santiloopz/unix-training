#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


void error(char * m) {
	write(2, m, strlen(m));
	write(2, "\n", 1);
	write(2, strerror(errno), strlen(strerror(errno)));
	exit(1);
}

int main() {
	int st;
	char s[80];


	switch (fork()) {

		case -1:
			// report the error and finish process
			error("Error forking process");

		case 0:
			// close stout channel
			close (1);
			// assign stdin to a file
			if (open("output.dat", O_WRONLY | O_CREAT, 0600) < 0) {
				error("Error opening file");
			}
			// now we are ready to output in the file
			execlp("bin/file-content-stdout", "bin/file-content-stdout", (char *)0);
			// we should't arrive here mate
			error("error running file-content-stdout");

		default:
			// parent process waiting for child to finish
			wait(&st);
			exit(0);

	}
}