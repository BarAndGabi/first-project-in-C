CC=gcc
OBJS=arrays.o Solution1.o exe.o  main.o Utill.o
EXEC=prog
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@


arrays.o: arrays.c arrays.h
Solution1.o: Solution1.c Solution1.h Utill.h arrays.h
exe.o: exe.c arrays.h Solution1.h exe.h Utill.h
main.o: main.c exe.h
Utill.o:Utill.h Utill.c 

clean: 
	rm -f $(EXEC) $(OBJS)
	
