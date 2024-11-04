// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 05/11/2024
// Archivo grammar.h: 
//          Contiene las definicion de la clase grammar.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          31/10/2024 - Creación (primera versión) del código

#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include "alphabet.h"

class Grammar {
 public:
  Grammar() = default;
  Grammar(const std::string& input);

  void Print();
  bool CheckIfEmptyProductions();
  bool CheckIfUnitaryProductions();
  void ChangeNonTerminalSymbol(char& symbol);
  void ConvertToCNF();

  friend std::ostream& operator<<(std::ostream& out, Grammar output_grammar);
 private:
  std::set<std::string> non_terminals_;
  Alphabet terminals_;
  std::string initial_;
  std::multimap<std::string, std::string> productions_;
};

#endif // GRAMMAR_H