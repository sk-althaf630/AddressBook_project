
invt.out : main.o create_db.o invt.o Display.o save_db.o search_db.o update_db.o
	gcc -o invt.out main.o create_db.o invt.o Display.o save_db.o search_db.o update_db.o
main.o : main.c
	gcc -c main.c
create_db : create_db.c
	gcc -c create_db.c 
invt.o : invt.c
	gcc -c invt.c 
Display.o : Display.c 
	gcc -c Display.c 
save_db.o : save_db.c 
	gcc -c save_db.c 
search_db.o : search_db.c 
	gcc -c search_db.c 
update_db.o : update_db.c 
	gcc -c update_db.c 
clean:
	rm * .out * .o