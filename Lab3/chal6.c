#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
	pid_t p;
	int fd[2], ret;

	ret = pipe(fd);
	if (ret < 0) {
		perror("pipe");
		exit(1);
	}

	dup2(fd[0], 33);
	dup2(fd[1], 34);
	p = fork();	

	if (p < 0) {
		perror("fork");
		exit(1);		
	}

	if (p == 0)
		execv("riddle", NULL);


	return 0;
}
