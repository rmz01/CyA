// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo symbol.cc: 
//          Contiene las implementacion de la clase symbol.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

#include <iostream>
#include "symbol.h"

/**
  * @brief Overload the operator <<
  * @param os A reference to an ostream object.
  * @param simbolo A reference to a Symbol object.
  * @return An ostream object.
  */
std::ostream& operator<<(std::ostream &os, const Symbol &simbolo){
  os << simbolo.getData();
  return os;
}