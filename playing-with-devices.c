#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> // definicions O_RDONLY, O_WRONLY, ...
#include <errno.h>
#include <string.h>


void error(char * m) {
	write(2, m, strlen(m));
	write(2, "\n", 1);
	write(2, strerror(errno), strlen(strerror(errno)));
	exit(1);
}

int main() {
	int fd, n;
	char c;

	if ((fd = open("data/datafile.dat", O_RDONLY)) < 0) {
		error("Opening file");
		// reads while there is info and writes throught the stdout
	}

	while ((n=read(fd, &c, 1)) > 0) {
		write(1, &c, 1);
		if (n < 0) {
			// finished reading file
			error("file finished reading");
			close (fd);
		}
	}
}