// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo alphabet.cc: 
//          Contiene las implementacion de la clase alphabet.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

#include "alphabet.h"

Alphabet::Alphabet() {
}


Alphabet::Alphabet(std::string string) {
  const char SPACE = ' ';
  symbols_.insert("&");
  for (unsigned i = 0; i < string.size(); i++) {
    if (string[i] != SPACE)
      symbols_.insert(std::string(1, string[i]));
  }
}

std::set<std::string>& Alphabet::getSymbols() {
  return symbols_;
}

Alphabet& Alphabet::operator=(Alphabet& alfabeto) {
  this->symbols_ = alfabeto.getSymbols();
  return *this;
}

std::ostream& operator<<(std::ostream& os, Alphabet& alfabeto) {
  os << "Alfabeto: " << alfabeto.getSymbols().size() << " { ";
  for (auto i = alfabeto.getSymbols().cbegin(); i != alfabeto.getSymbols().cend(); i++) {
    os << "'" << *i << "' ";
  }
  os << "}" << std::endl;
  return os;
}