#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main(void) {

	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	printf("\033[2J");
	printf("\033[1;1H");

	for (int i = 0; i < w.ws_row; i ++) {
		for (int j = 0; j < w.ws_col; j ++) {
			printf("\033[47m \033[m");
		}
		printf("\n");
	}

	return 0;
}
