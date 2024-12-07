# Compilador y banderas de compilación
CC = g++
CXXFLAGS = -g -Wall -std=c++17
ODIR = src

# Archivos objeto
_OBJ = point_types.o sub_tree.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Objetivo principal
all: point_types2CNF

# Regla para compilar el archivo main.cc
$(ODIR)/main.o: $(ODIR)/main.cc $(ODIR)/point_types.h $(ODIR)/sub_tree.h
	$(CC) -c -o $@ $< $(CXXFLAGS)

# Regla para compilar el archivo point_types.cc
$(ODIR)/point_types.o: $(ODIR)/point_types.cc $(ODIR)/point_types.h $(ODIR)/sub_tree.h
	$(CC) -c -o $@ $< $(CXXFLAGS)

# Regla para compilar el archivo sub_tree.cc
$(ODIR)/sub_tree.o: $(ODIR)/sub_tree.cc $(ODIR)/sub_tree.h
	$(CC) -c -o $@ $< $(CXXFLAGS)

# Enlace final para crear el ejecutable
point_types2CNF: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) -lm

# Limpiar archivos temporales y binarios
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o point_types2CNF
