// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo chain.cc: 
//          Contiene las implementacion de la clase chain.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

#include "chain.h"

// Inicializa el vector de simbolos con el vector de simbolos recibido
Chain::Chain(std::vector<std::string> chain): chain_(chain) {}

// Inicializa el vector de simbolos con los simbolos de la cadena recibida
Chain::Chain(std::string chain) {
  for (unsigned i = 0; i < chain.size(); i++)
    chain_.push_back(std::string(1, chain[i]));
}

// El constructor por defecto vacia la cadena
Chain::~Chain() {
  chain_.clear();
}

// getter cadena 
std::vector<std::string> Chain::getChain() {
  return chain_;
}

