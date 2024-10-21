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

/**
  * @brief Set the symbols_ object
  * @param string A const string reference.
  */
Alphabet::Alphabet(std::string string) {
  const char SPACE = ' ';
  symbols_.insert(Symbol("&"));
  for (unsigned i = 0; i < string.size(); i++) {
    if (string[i] != SPACE)
      symbols_.insert(Symbol(std::string(1, string[i])));
  }
}

/**
  * @brief Get the symbols_ object
  * @return The symbols_ value.
  */
std::set<Symbol>& Alphabet::getSymbols() {
  return symbols_;
}

/**
  * @brief Overload the operator =
  * @param alfabeto A reference to an Alphabet object.
  * @return An Alphabet object.
  */
Alphabet& Alphabet::operator=(Alphabet& alfabeto) {
  this->symbols_ = alfabeto.getSymbols();
  return *this;
}

/**
  * @brief Overload the operator <<
  * @param os A reference to an ostream object.
  * @param alfabeto A reference to an Alphabet object.
  * @return An ostream object.
  */
std::ostream& operator<<(std::ostream& os, Alphabet& alfabeto) {
  os << "Alfabeto: " << alfabeto.getSymbols().size() << " { ";
  for (auto i = alfabeto.getSymbols().cbegin(); i != alfabeto.getSymbols().cend(); i++) {
    os << "'" << *i << "' ";
  }
  os << "}" << std::endl;
  return os;
}