#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


void error(char *m) {
	write(2, m, strlen(m));
	write(2, "\n", 1);
	write(2, strerror(errno), strlen(strerror(errno)));
	exit(1);
}

int main(int argc, char *argv[]) {
	int source, dest, n;
	char c;

	if (argc != 3) {
		error("Wront number of arguments");
	}
	if ((source = open(argv[1], O_RDONLY)) < 0) {
		error("Opens to source file");
	}
	// if dest file exists, it's overwritten O_TRUNC
	// if it does not exists, it is created (O_CREAT, 0600)
	if ((dest = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0600)) < 0) {
		error("Creates dest file");
	}
	// reads font and writes in dest
	while ((n=read(source, &c, 1)) > 0) {		
		if (write(dest, &c, 1) < 0) {
			error("Dest file reading");
		}
	}
	if (n < 0) {
		error("Source file reading");
	}

	close (source);
	close (dest);
}
