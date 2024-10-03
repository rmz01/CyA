// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 18/09/2024
// Archivo alfabeto.h: 
//          Contiene la definición de la clase Alfabeto.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          18/09/2024 - Creación (primera versión) del código

#ifndef ALFABETO_H_
#define ALFABETO_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "simbolo.h"

/** Clase Alfabeto:
 * Esta clase está compuesta por un vector de objetos de la clase Símbolo para definir el alfabeto y un entero
 * llamado size_ para definir la longitud del alfabeto.
 * Se creó porque una cadena tiene que pertenecer a un alfabeto.
 * También incluye funciones como "verify" que comprueba que la cadena contiene los símbolos de un alfabeto.
 */
class Alfabeto {
 public:
  // constructores de la clase alfabeto
  Alfabeto() = default;
  Alfabeto(std::string my_string);

  //getters
  std::set<Simbolo> getAlphabet() const {return alphabet_;};
  int getSize() const {return alphabet_.size();}
  Simbolo getSymbol(std::set<Simbolo>::size_type n) const;

  //funciones
  void add(Simbolo symbol);
  bool verify(Simbolo symbol);

  //sobrecarga operador <<
  friend std::ostream& operator<<(std::ostream &os, const Alfabeto &alfabet);

 private:
  std::set<Simbolo> alphabet_;
};

#endif