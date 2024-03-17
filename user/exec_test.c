#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "kernel/fs.h"
#include "user/user.h""

//exec copy only memory, not all process
//default input stream
// 0 -> console
// 1 -/> console
// 1 -> out
int main() {
	int pid = fork();
	if(pid) {
		int status;
		wait(&status);
		printf("child ret %d\n", status);
	} else {
// first arg = <program name>, last arg = 0
		int fd = open("out", O_WROLNY | O_CREATE);
		(void)fd;
		char *arg[] = {"echo", "Hello", " ", "world", 0};
		exec("./echo", arg);
		printf("exec error\n");
		exit(1);
	}
	return 0;
}
