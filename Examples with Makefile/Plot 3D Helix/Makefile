CFLAGS = -ggdb
DEFINES = -DDEBUGGA
INCLUDES = 
LIBS = -lstdc++ -lhamzstplot
MAIN = main.o
CC=g++

.cc.o:
	$(CC) -c $(CFLAGS) $(DEFINES) $(INCLUDES) $<

all::	main

gnuplot_i.o:	
main.o:	main.cpp

main: $(MAIN)
	$(CC) -o $@ $(CFLAGS) $(MAIN) $(LIBS)

clean: 
	rm -f $(MAIN) main
