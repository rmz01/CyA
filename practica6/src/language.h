#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include <iostream>
#include <vector>
#include "symbol.h"

/** Clase Language:
 * Esta clase está compuesta por un vector de vectores de objetos de la clase Símbolo para definir el lenguaje.
 * Se creó porque una cadena tiene que pertenecer a un lenguaje.
 */
class Language {
 public:
  // Constructores de la clase Language
  Language() = default;
  Language(const std::vector<std::vector<Symbol>>& lenguaje) : language_(lenguaje) {}

  // Sobrecarga del operador <<
  friend std::ostream& operator<<(std::ostream &os, const Language &lenguaje);

 private:
  std::vector<std::vector<Symbol>> language_;
};

#endif