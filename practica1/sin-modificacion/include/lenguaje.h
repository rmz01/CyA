// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 18/09/2024
// Archivo lenguaje.h: 
//          Contiene la definición de la clase Lenguaje.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          18/09/2024 - Creación (primera versión) del código

#ifndef LENGUAJE_H_
#define LENGUAJE_H_

#include <iostream>
#include <vector>
#include "simbolo.h"

/** Clase Lenguaje:
 * Esta clase está compuesta por un vector de vectores de objetos de la clase Símbolo para definir el lenguaje.
 * Se creó porque una cadena tiene que pertenecer a un lenguaje.
 */
class Lenguaje {
 public:
  // Constructores de la clase Lenguaje
  Lenguaje() = default;
  Lenguaje(const std::vector<std::vector<Simbolo>>& lenguaje) : language_(lenguaje) {}

  // Sobrecarga del operador <<
  friend std::ostream& operator<<(std::ostream &os, const Lenguaje &lenguaje);

 private:
  std::vector<std::vector<Simbolo>> language_;
};

#endif