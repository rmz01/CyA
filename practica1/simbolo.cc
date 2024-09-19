// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 18/09/2024
// Archivo simbolo.cc: 
//          Contiene la implementación de la clase Simbolo y sus funciones.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          18/09/2024 - Creación (primera versión) del código

#include <iostream>
#include "simbolo.h"

// Constructor de la clase Simbolo
Simbolo::Simbolo(std::string data) {
  data_ = data;
}

// sobrecarga operador <<
std::ostream& operator<<(std::ostream &os, const Simbolo &symbol){
  os << symbol.getData();
  return os;
}