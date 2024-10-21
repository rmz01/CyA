// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo language.cc: 
//          Contiene las implementacion de la clase language.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

#include "language.h"

/**
 * @brief Overload the operator <<
 * @param os A reference to an ostream object.
 * @param lenguaje A reference to a Language object.
 * @return An ostream object.
 */
std::ostream& operator<<(std::ostream &os, const Language &lenguaje) {
  os << "{";
  for (const auto& subvec : lenguaje.language_) {
    for (const auto& simbolo : subvec) {
      os << simbolo.getData();
    }
    // Si el simbolo es distinto del ultimo de la subcadena, no se añade una coma
    if (&subvec != &lenguaje.language_.back()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}