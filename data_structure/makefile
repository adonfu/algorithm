GCC = gcc
CFLAGS = -g -Wall

objects = tmain.o single_loop_linkedlist.o
target=tmain

$(target):$(objects)
	$(GCC) $(CFLAGS) -o $(target) $(objects)

tmain.o:tmain.c
single_loop_linkedlist.o:single_loop_linkedlist.h linklisth.h

.PHONY:clean
clean:
	-rm $(target) $(objects)
