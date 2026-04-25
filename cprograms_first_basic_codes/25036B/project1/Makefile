address_book : main.o file.o  populate.o contact.o
	gcc -o address_book main.o file.o  populate.o contact.o
main.o: main.c
	gcc -c main.c
file.o: file.c
	gcc -c file.c
populate.o: populate.c
	gcc -c populate.c
contact.o: contact.c
	gcc -c contact.c
clean:
	rm *address_book *.o