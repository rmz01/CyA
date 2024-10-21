#include "language.h"

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