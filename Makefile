CC = gcc
CFLAGS = -Wall -std=c99

all: test

points_segments_qsort.o: points_segments_qsort.c string_matching.h
	$(CC) $(CFLAGS) -c string_matching_kmp.c
        
test.o: test.c string_matching.h
	$(CC) $(CFLAGS) -c test.c


test: string_matching_naive.o string_matching_kmp.o test.o
	$(CC) $(CFLAGS) -o test string_matching_naive.o string_matching_kmp.o test.o

clean:
	rm *.o test
