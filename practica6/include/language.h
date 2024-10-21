// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo language.h: 
//          Contiene la definicion de la clase language.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

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