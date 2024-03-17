#include "kernel/types.h"
#include "user/user.h"

int main() {
	int pid = fork();
	printf("fork test return %d\n");
	int status;
	if(pid) {
//		pid = fork();
//		if(pid) {
//			wait(&status);
			wait(&status);
			printf("parent: child return %x\n", status);
		}
	} else {
		printf("child\n");
		exit(0xdeadbeef);
	}
	return 0;
}
