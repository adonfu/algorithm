GCC = gcc
CFLAGS = -g -Wall

objects = tmain.o single_linkedlist.o
target=tmain

$(target):$(objects)
	$(GCC) $(CFLAGS) -o $(target) $(objects)

tmain.o:tmain.c
single_linkedlist.o:single_linkedlist.h ../linklisth.h

.PHONY:clean
clean:
	-rm $(target) $(objects)
