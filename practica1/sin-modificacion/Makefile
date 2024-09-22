# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
TEST_DIR = test

# Archivos fuente y objeto
SRC_FILES = $(filter-out $(SRC_DIR)/cya-P02.cc, $(wildcard $(SRC_DIR)/*.cc))
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRC_FILES))
EXEC = cya-P02

# Target principal
all: $(EXEC)

# Compilación del ejecutable principal
$(EXEC): $(OBJ_FILES) $(BUILD_DIR)/cya-P02.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los archivos fuente a objetos (excepto cya-P02.cc)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc $(INCLUDE_DIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla específica para compilar cya-P02.cc (sin dependencia de un encabezado)
$(BUILD_DIR)/cya-P02.o: $(SRC_DIR)/cya-P02.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos objeto y el ejecutable
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC)