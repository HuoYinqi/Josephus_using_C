SHELL=cmd.exe
OBJS=test.o person.o josephus.o reader.o
main: $(OBJS)
		gcc -o test $(OBJS)
test.o:
		gcc -c test.c
person.o:
		gcc -c person.c
josephus.o:
		gcc -c josephus.c
reader.o:
		gcc -c reader.c
clean:
		del $(OBJS)