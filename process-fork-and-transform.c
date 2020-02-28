#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// TODO: ask doubt about compile time errors
int main() {
	int process, st, pid;
	char s[80];

	switch (process = fork()) {

	case -1:
		sprintf(s, "There was an error in the fork\n");
		write(2, s, strlen(s));
		exit(1);

	case 0:
		execlp("ls", "ls", (char *)0);
		// if we get here, there is an error, which is reported and we finish
		sprintf(s, "Error exec\n");
		write(2, s, strlen(s));
		exit(1);

	default:
		write(1, s, strlen(s));
		exit(0);

	}
}