CPP=clang++
CPPFLAGS=-g -Wall -std=c++20

SRC=src
BIN=bin
DEP=numtheory

all:
	@echo No make all rule. Use \'make bin/xxxx\'

$(BIN)/%: $(BIN)/%.o $(BIN)/$(DEP).o
	$(CPP) $(CPPFLAGS) $? -o $@

$(BIN)/%.o: $(SRC)/%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(BIN)/$(DEP).o: $(SRC)/$(DEP).cpp $(SRC)/$(DEP).h
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -r $(BIN)/*