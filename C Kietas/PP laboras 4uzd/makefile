CC = gcc

MAIN = program
TEST = tests

MAIN_OBJS = main.o list.o
TEST_OBJS = test.o list.o

all: $(MAIN)

$(MAIN): $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJS) -o $(MAIN)

main.o: main.c list.h
	$(CC) -c main.c

list.o: list.c list.h
	$(CC) -c list.c

$(TEST): $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $(TEST)

test.o: test.c list.h
	$(CC) -c test.c

run-tests: $(TEST)
	./$(TEST)

run : $(MAIN)
	./$(MAIN)

clean:
	rm -f *.o $(MAIN) $(TEST)
