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


/**
  * @brief constructor of the class Chain
  * @param chain A vector of strings.
  */
Chain::Chain(std::vector<Symbol> chain): chain_(chain) {}

/**
  * @brief constructor of the class Chain
  * @param chain A string.
  */
Chain::Chain(std::string chain) {
  for (unsigned i = 0; i < chain.size(); i++)
    chain_.push_back(std::string(1, chain[i]));
}

/**
  * @brief destructor of the class Chain
  */
Chain::~Chain() {
  chain_.clear();
}

/**
  * @brief Get the chain_ object
  * @return The chain_ value.
  */
std::vector<Symbol> Chain::getChain() {
  return chain_;
}