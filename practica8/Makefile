# Compilador y banderas de compilación
CC = g++
CXXFLAGS = -g -Wall -std=c++17
ODIR = src

# Archivos objeto
_OBJ = grammar.o alphabet.o main.o functions.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Objetivo principal
all: Grammar2CNF

# Regla para compilar el archivo main.cc
$(ODIR)/main.o: $(ODIR)/main.cc $(ODIR)/grammar.h $(ODIR)/alphabet.h
	$(CC) -c -o $@ $< $(CXXFLAGS)

# Regla para compilar el archivo grammar.cc
$(ODIR)/grammar.o: $(ODIR)/grammar.cc $(ODIR)/grammar.h $(ODIR)/alphabet.h
	$(CC) -c -o $@ $< $(CXXFLAGS)

# Regla para compilar el archivo alphabet.cc
$(ODIR)/alphabet.o: $(ODIR)/alphabet.cc $(ODIR)/alphabet.h
	$(CC) -c -o $@ $< $(CXXFLAGS)

# Regla para compilar el archivo functions.cc
$(ODIR)/functions.o: $(ODIR)/functions.cc $(ODIR)/functions.h
	$(CC) -c -o $@ $< $(CXXFLAGS)

# Enlace final para crear el ejecutable
Grammar2CNF: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) -lm

# Limpiar archivos temporales y binarios
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o Grammar2CNF
