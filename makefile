SHELL=cmd.exe
OBJS=main.o person.o josephus.o read_file.o
main: $(OBJS)
		gcc -o main $(OBJS)
main.o:
		gcc -c main.c
person.o:
		gcc -c src/person.c
josephus.o:
		gcc -c src/josephus.c
read_file.o:
		gcc -c src/read_file.c
clean:
		del $(OBJS)