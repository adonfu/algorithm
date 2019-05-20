GCC = gcc
CFLAGS = -g -Wall

objects = substring_search.o
target=substring_search

main:$(objects)
	$(GCC) $(CFLAGS) -o $(target) $(objects)

.PHONY:clean
clean:
	-rm $(target) $(objects)
