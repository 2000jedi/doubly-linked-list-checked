CC = /mnt/disk/checkedc/build/bin/clang
PROGRAMS = test
CFLAGS = -g -O3 -std=c99 -Wall

programs: $(PROGRAMS)

test: test.o linkedlist.o print.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	-rm $(PROGRAMS) *.o
	-rm -r *.dSYM
	-rm test