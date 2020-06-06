SHELL=cmd.exe
OBJS=main.o person.o josephus.o read_file.o
main: $(OBJS)
		gcc -o main $(OBJS)
main.o:
		gcc -c main.c
person.o: person.c
		gcc -c person.c
josephus.o: josephus.c
		gcc -c josephus.c
read_file.o: read_file.c
		gcc -c read_file.c
clean:
		del $(OBJS)