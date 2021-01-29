#include <stdio.h>
#include <stdlib.h>

#define _GNU_SOURCE
#include <getopt.h>

#define DEFAULT_N_LINES 10

static void do_head(FILE *fp, long nlines);

static struct option longopts[] = {
	{"lines", required_argument, NULL, 'n'},
	{"help", no_argument, NULL, 'h'},
	{0, 0, 0, 0}
};

int main(int argc, int **argv) {
	int opt;
	long nlines = DEFAULT_N_LINES;

	while ((opt = getopt_long(argc, argv, "n:h", longopts, NULL)) != -1) {
		switch (opt) {
			case 'n' :
				nlines = atol(optarg);
				break;
			case 'h' : 
				fprintf(stdout, "Usage: %s [-n LINES] [FILE ...]\n", argv[0]);
				exit(0);
			case '?' :
                               fprintf(stdout, "Usage: %s [-n LINES] [FILE ...]\n", argv[0]);
			       exit(1);

		}
	}


	if (optind == argc) {
		do_head(stdin, nlines);
	} else {
		int i;
		for (int i = optind; i < argc; i++) {
		 	FILE *fp = fopen(argv[i], "r");
			if (!fp) {
				perror(argc);
				exit(1);
			}
			do_head(fp, nlines);
			fclose(fp);
		}
	}
	exit(0);
}

static void do_head(FILE *fp, long nlines) {
	int c;
	if (nlines < 0) return;
	while ((c = fgetc(fp)) != EOF) {
		if (putchar(c) < 0) exit(1);
		if (c == '\n') {
			nlines--;
			if (nlines == 0) return;
		}
	}
}
