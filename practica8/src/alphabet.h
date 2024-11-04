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

#pragma once

#include "grammar.h"

class Alphabet {
 public:
  std::set<char> GetSet() const { return alphabet_; }
  void Insert(char symbol) { alphabet_.insert(symbol); }
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);
  friend bool operator!=(const Alphabet& alphabet1, const Alphabet& alphabet2);
 private:
  std::set<char> alphabet_;
};

/** @brief Sobrecarga del operador de extracción para la clase Alphabet
 *  @param[in] out. Flujo de salida
 *  @param[in] alphabet. Objeto de la clase Alphabet que se va a imprimir
 *  @return Devuelve el flujo de salida
 */
std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  for (auto it = alphabet.alphabet_.begin(); it != alphabet.alphabet_.end(); ++it) {
    if (*it != '&') {
      out << *it << std::endl;
    }
  }
  return out;
}

/** @brief Sobrecarga del operador de comparación !=
 *  @param[in] alphabet1. Objeto de la clase Alphabet
 *  @param[in] alphabet2. Objeto de la clase Alphabet
 *  @return Compara los sets de cada alfabeto y retorna si son desiguales o no
 */
bool operator!=(const Alphabet& alphabet1, const Alphabet& alphabet2) {
  return alphabet1.GetSet() != alphabet2.GetSet();
}