CPPFLAGS=-g
SRCS = \
block.cpp \
board.cpp \
boardcomparison.cpp \
candidates.cpp \
cell.cpp \
column.cpp \
grid.cpp \
main.cpp \
point.cpp \
row.cpp \
sudoku.cpp \
sudokucallback.cpp \
sudokuinit.cpp 
OBJS = $(SRCS:.cpp=.o)
.PHONY: all
sudoku:	$(OBJS)
		echo $(OBJS)
		g++ -g -o $@ $(OBJS)
virtual: virtual.o
		g++ -g -o virtual virtual.o
clean:
		rm -f $(OBJS)
