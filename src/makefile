SHELL=cmd.exe
OBJS=test.o person.o josephus.o read_file.o
main: $(OBJS)
		gcc -o test $(OBJS)
test.o:
		gcc -c test.c
person.o:
		gcc -c person.c
josephus.o:
		gcc -c josephus.c
read_file.o:
		gcc -c read_file.c
clean:
		del $(OBJS)