// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 18/09/2024
// Archivo lenguaje.cc: 
//          Contiene la implementacion de la clase Lenguaje.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          18/09/2024 - Creación (primera versión) del código

#include "lenguaje.h"

std::ostream& operator<<(std::ostream &os, const Lenguaje &lenguaje) {
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