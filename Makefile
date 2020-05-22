all : prog clean
prog : main.o utilities.o info.o
	@echo "building..."
	gcc main.c info.c utilities.c -o prog
clean:
	@echo "cleaning up..."
	rm *.o