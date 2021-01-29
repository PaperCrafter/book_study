CC = gcc
CFLAGS = -W -Wall -O2 -g
LDFLAGS = -lm

cat : cat.c
	$(CC) $(CFLAGS) -o $@ $^ #(LDFLAGS)

clean :
	@rm -rf *.o cat
