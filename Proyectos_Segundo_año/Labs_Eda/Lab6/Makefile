objcoste= costes.o alumno.o
objtabla= test_tabla.o alumno.o
CC= g++
WARNING = -Wall
LIB=

todo: programacoste programatabla

alumno.o: alumno.h alumno.cpp
	$(CC) -O2 -c alumno.cpp $(WARNING)

costes.o: costes.cpp tabla.h alumno.h abb.h
	$(CC) -O2 -c costes.cpp $(WARNING)
	
test_tabla.o: test_tabla.cpp alumno.h tabla.h
	$(CC) -O2 -c test_tabla.cpp $(WARNING)
	
programacoste: $(objcoste)
	$(CC) $(objcoste) -O2 -o  programacoste $(LIB)
	
programatabla: $(objtabla)
	$(CC) $(objtabla) -O2 -o  programatabla $(LIB)

clean:
	rm -f programacoste programatabla *.o *.txt 
