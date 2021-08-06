CXX=g++-10
CXXFLAGS=-Wall -Werror -std=c++2a

S=sudoku

SRC_FILES= $(S)/read.cc $(S)/print.cc $(S)/fitsRow.cc $(S)/fitsCol.cc \
$(S)/fitsUnit.cc $(S)/next.cc $(S)/solve.cc
OBJ_FILES= $(S)/read.o $(S)/print.o $(S)/fitsRow.o $(S)/fitsCol.o \
$(S)/fitsUnit.o $(S)/next.o $(S)/solve.o

main: main.cc $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) main.cc $(OBJ_FILES) -o sudokusolver

OBJ_FILES: $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -c $(SRC_FILES)

clean:
	rm -f $(OBJ_FILES) main
