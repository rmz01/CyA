# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
TEST_DIR = test

# Archivos fuente y objeto
SRC_FILES = $(filter-out $(SRC_DIR)/p06_automata_simulator.cc, $(wildcard $(SRC_DIR)/*.cc))
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRC_FILES))
EXEC = p06_automata_simulator

# Target principal
all: $(EXEC)

# Compilación del ejecutable principal
$(EXEC): $(OBJ_FILES) $(BUILD_DIR)/p06_automata_simulator.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los archivos fuente a objetos (excepto p06_automata_simulator.cc)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc $(INCLUDE_DIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla específica para compilar p06_automata_simulator.cc (sin dependencia de un encabezado)
$(BUILD_DIR)/p06_automata_simulator.o: $(SRC_DIR)/p06_automata_simulator.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos objeto y el ejecutable
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC)