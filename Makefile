CC=gcc
OBJS=arrays.o Solution1.o exe.o  main.o Utill.o Solution3.o Solution2.o
EXEC=prog
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@


arrays.o: arrays.c arrays.h
Solution1.o: Solution1.c Solution1.h Utill.h arrays.h
Solution2.o: Solution2.c Solution2.h Utill.h arrays.h
Solution3.o: Solution3.c Solution3.h Utill.h arrays.h
exe.o: exe.c arrays.h Solution1.h Solution2.h Solution3.h exe.h Utill.h
main.o: main.c exe.h
Utill.o:Utill.h Utill.c 

clean: 
	rm -f $(EXEC) $(OBJS)
	
