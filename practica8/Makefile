# Nombre del compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Archivos fuente
SOURCES = main.cc grammar.cc

# Archivos objeto
OBJECTS = $(SOURCES:.cc=.o)

# Archivo ejecutable
EXECUTABLE = Grammar2CNF

# Regla por defecto
all: $(EXECUTABLE)

# Regla para compilar el ejecutable
$(EXECUTABLE): $(OBJECTS)
    $(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos objeto
%.o: %.cc
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
    rm -f $(OBJECTS) $(EXECUTABLE)

# Regla para limpiar y recompilar
rebuild: clean all

.PHONY: all clean rebuild