CC=g++
CXXFLAGS=-g -std=c++17
ODIR=src
BUILD=build

_OBJ=$ $(BUILD)/symbol.o $(BUILD)/alphabet.o $(BUILD)/chain.o $(BUILD)/language.o $(BUILD)/state.o $(BUILD)/automaton.o $(BUILD)/p06_automata_simulator.o
OBJ=$(patsubst %,%,$(_OBJ))

all:p06_automata_simulator
$(BUILD)/p06_automata_simulator.o: $(ODIR)/p06_automata_simulator.cc
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/symbol.o: $(ODIR)/symbol.cc
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/alphabet.o: $(ODIR)/alphabet.cc
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/chain.o: $(ODIR)/chain.cc
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/language.o: $(ODIR)/language.cc
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/state.o: $(ODIR)/state.cc
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/automaton.o: $(ODIR)/automaton.cc
	$(CC) -c -o $@ $< $(CXXFLAGS)

p06_automata_simulator: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) -lm

.PHONY:clean

clean:
	rm -rf build/* p06_automata_simulator
