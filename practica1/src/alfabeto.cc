// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 18/09/2024
// Archivo alfabeto.cc: 
//          Contiene la implementación de la clase Alfabeto y sus funciones.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          18/09/2024 - Creación (primera versión) del código

#include "alfabeto.h"

// Constructor para la clase Alfabeto
Alfabeto::Alfabeto(std::string my_string) {
  for (char c : my_string) {
    Simbolo symbol(std::string(1, c));
    alphabet_.insert(symbol);
  }
}

// Añade un Símbolo al alfabeto
void Alfabeto::add(Simbolo symbol) {
  if (!verify(symbol)) {
    alphabet_.insert(symbol);
  }
}

// Verifica si el símbolo pertenece al alfabeto
bool Alfabeto::verify(Simbolo symbol) {
  return alphabet_.find(symbol) != alphabet_.end();
}

Simbolo Alfabeto::getSymbol(std::set<Simbolo>::size_type n) const {
  if (n >= alphabet_.size()) {
    throw std::out_of_range("Index out of range");
  }
  auto it = alphabet_.begin();
  std::advance(it, n);
  return *it;
}

// Funcion para poder imprimir el alfabeto en ficheros
std::ostream& operator<<(std::ostream &os, const Alfabeto &alfabet) {
  os << "{";
  for (auto it = alfabet.alphabet_.begin(); it != alfabet.alphabet_.end(); ++it) {
    if (it != alfabet.alphabet_.begin()) {
      os << ",";
    }
    os << *it;
  }
  os << "}";
  return os;
}