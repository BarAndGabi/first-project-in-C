CC=gcc
OBJS=arrays.o functions4.o exe.o  main.o
EXEC=lab4
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@


arrays.o: arrays.c arrays.h
functions4.o: functions4.c functions4.h
exe.o: exe.c arrays.h functions4.h exe.h
main.o: main.c exe.h

clean: 
	rm -f $(EXEC) $(OBJS)
	
