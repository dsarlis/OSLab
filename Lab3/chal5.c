#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
	pid_t p;


	dup2(0, 99);
	p = fork();	

	if (p < 0) {
		perror("fork");
		exit(1);		
	}

	if (p == 0)
		execv("riddle", NULL);


	return 0;
}
