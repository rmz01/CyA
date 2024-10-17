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

State::State() {
}

State::State(unsigned id, bool aceptacion) {
  id_ = id;
  aceptacion_ = aceptacion;
}

unsigned State::getID() {
  return id_;
}

bool State::Accepted() {
  return aceptacion_;
}

void State::addTransition(std::string symbol, unsigned estado) { 
  transiciones_[symbol].push_back(estado);  
}

std::vector<unsigned> State::getTransition(std::string symbol) {
  return transiciones_[symbol];
}

std::vector<unsigned> State::getStates(std::string symbol) {
  return transiciones_[symbol];  
}