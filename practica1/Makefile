CXXFLAGS = -g -Wall
CXX = g++
OBJS = $(TARGET).o lenguaje.o cadena.o alfabeto.o simbolo.o functions.o
TARGET = cya-P01-Strings

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o p01_strings

$(TARGET).o : $(TARGET).cc
	@$(CXX) -c $(CXXFLAGS) $(TARGET).cc

lenguaje.o : lenguaje.cc lenguaje.h
	@$(CXX) -c $(CXXFLAGS) lenguaje.cc

cadena.o : cadena.cc cadena.h
	@$(CXX) -c $(CXXFLAGS) cadena.cc

alfabeto.o : alfabeto.cc alfabeto.h
	@$(CXX) -c $(CXXFLAGS) alfabeto.cc

simbolo.o : simbolo.cc simbolo.h
	@$(CXX) -c $(CXXFLAGS) simbolo.cc

functions.o : functions.cc functions.h
	@$(CXX) -c $(CXXFLAGS) functions.cc

.PHONY: clean
clean:
	rm -f *.o p01_strings