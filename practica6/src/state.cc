// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo state.cc: 
//          Contiene la implemetacion de la clase state.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

#include "state.h"

/**
  * @brief constructor of the class State
  * @param id An unsigned.
  * @param aceptacion A bool.
  */
State::State(unsigned id, bool aceptacion) {
  id_ = id;
  aceptacion_ = aceptacion;
}

/**
  * @brief Get the id_ object
  * @return The id_ value.
  */
unsigned State::getID() {
  return id_;
}

/**
  * @brief Get the aceptacion_ object
  * @return The aceptacion_ value.
  */
bool State::Accepted() {
  return aceptacion_;
}

/**
  * @brief Set the transiciones_ object
  * @param symbol A string reference.
  * @param estado An unsigned.
  */
void State::addTransition(Symbol simbolo, unsigned estado) { 
  transiciones_[simbolo].push_back(estado); 
}

/**
  * @brief Get the transiciones_ object
  * @param symbol A string reference.
  * @return The transiciones_ value.
  */
std::vector<unsigned> State::getTransition(Symbol simbolo) {
  return transiciones_[simbolo];
}

/**
  * @brief Get the transiciones_ object
  * @param symbol A string reference.
  * @return The transiciones_ value.
  */
std::vector<unsigned> State::getStates(Symbol simbolo) {
  return transiciones_[simbolo];  
}