compile: main.c 
	 gcc main.c -o film

run: film
	 ./film

clean: film
	 rm film
