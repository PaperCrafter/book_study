#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void do_cat(const char *path);
static void print_error(const char *s);

int main(int argv, int **args) {
	int i;
	if (argv < 2) {
		fprintf(stderr, "%s file name is not given");
		exit(1);
	}
	
	for (int i = 0; i < argv; i++) {
		do_cat(args[i]);
	}

}

#define BUFFER_SIZE 2048

static void do_cat(const char *path) {
	int fd;
	unsigned char buff[BUFFER_SIZE];
	int word_num = 0;

	fd = open(path, O_RDONLY);
	if (fd < 0) {
		print_error("invalid path or file name");
	}

	while (1) {
		if (word_num = read(fd, buff, sizeof(buff) < 0)) print_error(path);
		if (word_num == 0) break;
		if (write(STDOUT_FILENO, buff, word_num) < 0) print_error(path);
		
	}
	if (close(fd) < 0) print_error(path);
}

static void print_error(const char *s) {
	perror(s);
	exit(1);
}
