#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

static void do_ls(char *path);

int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "%s: no arguments\n", argv[0]);
		exit(1);
	}

	for (int i = 1; i < argc; i++) {
		do_ls(argv[i]);
	}

}

static void do_ls(char* path) {
	DIR *dir = opendir(path);
	struct dirent *ent;
	if (!dir) {
		perror(path);
		exit(1);
	}

	while (ent = readdir(dir)) {
		printf("%s\n", ent->d_name);
	}

	closedir(dir);
}
