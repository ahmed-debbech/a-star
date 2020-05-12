all : prog clean
prog : main.o utilities.o
	@echo "building..."
	gcc main.c utilities.c -o prog
clean:
	@echo "cleaning up..."
	rm *.o