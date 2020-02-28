# include <stdlib.h>
# include <stdio.h>
# include <string.h>


int main() {
	int process, st, pid;
	char s[80];

	switch (process = fork()) {

	case -1:
		sprintf(s, "There was an error in the fork\n");
		write(2, s, strlen(s));
		exit(1);

	case 0:
		sprintf(s, "Whaaaa!! You just had a child!!!\n");
		write(1, s, strlen(s));
		exit(0);

	default:
		sprintf(s, "I am the father process and my child is: %d\n", process);
		write(1, s, strlen(s));
		pid = wait(&st);
		exit(0);

	}
}