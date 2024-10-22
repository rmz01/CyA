// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo automaton.cc: 
//          Contiene las definicion de la clase automaton.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

#include "automaton.h"


/**
  * @brief constructor of the class Automaton
  * @param inputAutomata A string reference.
  * @param inputStrings A string reference.
  */
Automaton::Automaton(std::string inputAutomata, std::string inputStrings) {
  std::string line;
  std::ifstream fileAutomata(inputAutomata);
  std::getline(fileAutomata, line);   
  Alphabet alfabeto(line);  // Alfabeto
  int nEntradas;
  fileAutomata >> nEntradas;  // Numeros de estados
  fileAutomata >> start_;   // estado inicial

  unsigned nombreEstado, nombreEstadoActual;
  int estadoAceptacion, nTransiciones;
  std::string transicion;
  for (int i = 0; i < nEntradas; i++) {
    fileAutomata >> nombreEstado; // q1, q2, q3 ...
    fileAutomata >> estadoAceptacion; // 0 no es de aceptacion. 1 es de aceptacion
      
    states_[nombreEstado] = new State(nombreEstado, estadoAceptacion);  // creo un nuevo estado que contendra las trancisiones de mi estado base
    fileAutomata >> nTransiciones;  // numero de transiciones que hace el estado base

    for (int j = 0; j < nTransiciones; j++) {
      fileAutomata >> transicion; // trancision actual mostrada
      fileAutomata >> nombreEstadoActual; // nombre de dicha transicion mostrada
      states_[nombreEstado]->addTransition(transicion, nombreEstadoActual); // guardamos las transiciones de mi estado base
    }
  }

  // Por cada cadena la analizamos con el Automata
  std::ifstream inStrings(inputStrings);
  std::string line1;
  while (std::getline(inStrings, line1)) {
    evaluate(line1); // evalua si la cadena introducida es aceptada
  }
}

/**
  * @brief evaluate if the string is accepted by the automaton
  * @param string A string reference.
  * @return A bool.
  */
bool Automaton::evaluate(std::string string) {
  bool isAccepted = false;
  actualStates_.clear();
  actualStates_.insert(start_); // comienzo en el nodo inicial
  std::set<unsigned> transitedStates;
  std::string symbol;

  // Procesar transiciones epsilon iniciales
  processEpsilonTransitions();

  // Calculamos para cada estado actual, el conjunto transitado
  for (size_t i = 0; i < string.size(); i++) {
    symbol = string[i];
    // Transitamos al propio estado
    if (symbol == "&") {
      transitedStates = actualStates_;
    }
    for (unsigned state : actualStates_) {
      for (unsigned stateIDs : states_[state]->getTransition(symbol)){
        transitedStates.insert(stateIDs);
      }
    }
    actualStates_ = transitedStates;
    transitedStates.clear();
  }

  // Procesar transiciones epsilon después de cada símbolo
  processEpsilonTransitions();

  // Reviso si estamos en un estado de aceptacion
  for (unsigned state : actualStates_) {
    if (states_[state]->Accepted()) {
      isAccepted = true;
    }
  }
  // Operador ternario que evalua si es aceptada la cadena o no
  std::cout << string << ((isAccepted)?" --- Accepted" : " --- Rejected") << std::endl;
  return isAccepted;
}

void Automaton::processEpsilonTransitions() {
  std::set<unsigned> epsilonStates;
  std::set<unsigned> toProcess = actualStates_;

  while (!toProcess.empty()) {
    std::set<unsigned> newStates;
    for (unsigned state : toProcess) {
      for (unsigned epsilonState : states_[state]->getEpsilonTransitions()) {
        if (actualStates_.insert(epsilonState).second) {
          newStates.insert(epsilonState);
        }
      }
    }
    toProcess = newStates;
  }
}