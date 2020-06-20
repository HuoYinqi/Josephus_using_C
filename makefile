SHELL=cmd.exe
OBJS=main.o person.o josephus.o reader.o
main: $(OBJS)
		gcc -o main $(OBJS)
main.o:
		gcc -c main.c
person.o:
		gcc -c src/person.c
josephus.o:
		gcc -c src/josephus.c
reader.o:
		gcc -c src/reader.c
clean:
		del $(OBJS)