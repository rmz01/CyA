// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 05/11/2024
// Archivo alphabet.h: 
//          Contiene las definicion de la clase alphabet.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          31/10/2024 - Creación (primera versión) del código

#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <set>

class Alphabet {
 public:
  std::set<char> GetSet() const { return alphabet_; }
  void Insert(char symbol) { alphabet_.insert(symbol); }
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);
  friend bool operator!=(const Alphabet& alphabet1, const Alphabet& alphabet2);
 private:
  std::set<char> alphabet_;
};

#endif // ALPHABET_H