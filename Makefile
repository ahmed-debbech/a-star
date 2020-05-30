all : prog clean
prog : main.o utilities.o info.o algo.o
	@echo "building..."
	gcc main.c info.c utilities.c algo.o -o prog
clean:
	@echo "cleaning up..."
	rm *.o