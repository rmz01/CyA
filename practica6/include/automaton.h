// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo automaton.h: 
//          Contiene las definicion de la clase automaton.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

#ifndef __Automata__
#define __Automata__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 
#include "alphabet.h"
#include "state.h"

class Automaton {
 public:
    Automaton() = default;
    Automaton(std::string automata, std::string strings);
    bool evaluate(std::string string);
    void processEpsilonTransitions(); // Nueva función para procesar transiciones epsilon


 private:
    unsigned start_;
    std::map<unsigned, State*> states_;
    std::set<unsigned> actualStates_;

};

#endif