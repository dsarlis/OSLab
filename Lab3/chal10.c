#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	int fd, cnt, res;
	pid_t p;
	char buf[4096];
	ssize_t ret;
	FILE *f;

	fd = open("secret_number", O_RDONLY|O_CREAT);
	if (fd < 0) {
		perror("open");
		exit(1);
	}

	unlink("secret_number");
	p = fork();
	if (p < 0) {
		perror("fork");
		exit(1);
	}

	if (p == 0)
		execv("riddle", NULL);

	sleep(5);

	ret = read(fd, buf, 4096);
	if (ret < 0 ) {
		perror("write");
		exit(1);
	}

	f = fopen("out.txt", "w");

	fprintf(f, "%s\n", buf);

	if (close(fd) < 0) {
		perror("close");
		exit(1);
	}

	return 0;
}
