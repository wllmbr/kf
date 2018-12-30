CC = gcc
NAME = kalmanTest

#Auto file grabbing
INIT = main.c
FILES = $(wildcard *.c)
LIBS = $(filter-out $(INIT), $(FILES))
OBJS = $(patsubst %.c, $(BLD)/%.o, $(LIBS))
BLD = bld

WARN = -Wall -Wno-unused-variable
OPT = -O3 -g
LINK = -pthread


EXE = $(NAME).exe
DIS = $(NAME).asm


all: $(EXE) $(DIS)
	echo $(LIBS)

$(DIS): $(EXE)
	objdump -d -l --source --prefix=FB --prefix-strip=6 $(EXE) > $@

$(EXE): $(INIT) $(OBJS)
	$(CC) $(WARN) $(OPT) -o $@ $^

$(BLD)/%.o: %.c
	$(CC) $(WARN) $(OPT) -o $@ -c $^

$(BLD)/%.o: %.c %.h
	$(CC) $(WARN) $(OPT) -o $@ -c $^

.PHONY: all clean remake debug

debug: $(EXE)
	gdb $(EXE)

clean:
	rm -rf $(BLD)/* *.o *.exe *.asm

remake:
	make clean; make