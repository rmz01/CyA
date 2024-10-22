// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo state.h: 
//          Contiene las definicion de la clase state.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

#ifndef __State__
#define __State__

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#include "string.h"
#include "symbol.h"

/* 
Clase que representa un estado de un automata finito. Cada estado tiene un identificador, un booleano que 
indica si es de aceptacion y un map que contiene las transiciones que puede realizar.
*/
class State {
 public:
  State() = default;
  State(unsigned id, bool aceptacion = false);

  unsigned getID();
  bool Accepted();
  void addTransition(Symbol simbolo, unsigned estado);
  std::vector<unsigned> getStates(Symbol simbolo);
  std::vector<unsigned> getTransition(Symbol simbolo);
  std::vector<unsigned> getEpsilonTransitions();

  State& operator=(State& a);
  friend std::ostream& operator<<(std::ostream& os, State& a);

  private:
    unsigned id_;
    bool aceptacion_;
    std::map<Symbol, std::vector<unsigned>> transiciones_;
};

#endif
