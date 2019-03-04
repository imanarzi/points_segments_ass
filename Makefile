CC = gcc
CFLAGS = -Wall -std=c99

all: test

points_segments_qsort.o: points_segments_qsort.c points_segments.h
	$(CC) $(CFLAGS) -c points_segments_qsort.c
        
test.o: test.c points_segments.h
	$(CC) $(CFLAGS) -c test.c

test: points_segments_qsort.o test.o
	$(CC) $(CFLAGS) -o test points_segments_qsort.o test.o

clean:
	rm *.o test
