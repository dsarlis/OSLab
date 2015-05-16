#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	int fd, cnt, res;
	ssize_t ret;

	fd = open(argv[1], O_WRONLY);
	if (fd < 0) {
		perror("open");
		exit(1);
	}
	res = lseek(fd, 1073741824, SEEK_SET);
	if (res < 0) {
		perror("lseek");
		exit(1);
	}

	cnt = 16;

	do {
		ret = write(fd, "XXXXXXXXXXXXXXXX", 16);
		if (ret < 0 ) {
			perror("write");
			exit(1);
		}
		cnt -= ret;
	}while (cnt > 0);


	if (close(fd) < 0) {
		perror("close");
		exit(1);
	}

	return 0;
}
