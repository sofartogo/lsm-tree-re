CC = gcc 
DEBUG = -g -ggdb -DDEBUG
CFLAGS = -c -std=c99 -W -Wall -Werror -fPIC $(DEBUG)

LIB_OBJS = \
		   ./src/sst.o\
		   ./src/log.o\
		   ./src/util.o\
		   ./src/meta.o\
		   ./src/index.o\
		   ./src/skiplist.o\
		   ./src/buffer.o\
		   ./src/debug.o

LIBRARY = liblsmtree.so

all: $(LIBRARY)

clean:
	-rm -f bench src/bench.o
	-rm -f $(LIBRARY)
	-rm -f $(LIB_OBJS)

cleandb:
	-rm -rf ndbs
	-rm -rf *.event

$(LIBRARY) : $(LIB_OBJS)
	$(CC) -pthread -fPIC -shared $(LIB_OBJS) -o $(LIBRARY)

bench: src/bench.o $(LIB_OBJS)
	$(CC) -pthread src/bench.o $(LIB_OBJS) -o $@
