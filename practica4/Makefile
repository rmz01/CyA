CC=g++
CXXFLAGS=-g -std=c++17
ODIR=src
BUILD=build

_OBJ=$(BUILD)/comment.o $(BUILD)/statement.o $(BUILD)/variable.o $(BUILD)/code_analyzer.o $(BUILD)/p04_code_analyzer.o
OBJ=$(patsubst %,%,$(_OBJ))

all:p04_code_analyzer
$(BUILD)/p04_code_analyzer.o: $(ODIR)/p04_code_analyzer.cc
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/code_analyzer.o: $(ODIR)/code_analyzer.cc
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/comment.o: $(ODIR)/comment.cc
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/statement.o: $(ODIR)/statement.cc
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/variable.o: $(ODIR)/variable.cc
	$(CC) -c -o $@ $< $(CXXFLAGS)

p04_code_analyzer: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) -lm

.PHONY:clean

clean:
	rm -rf build/* p04_code_analyzer
