// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo chain.h: 
//          Contiene la definicion de la clase chain.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

#ifndef __CHAIN__
#define __CHAIN__

#include <iostream>
#include <vector>
#include <string>
#include "symbol.h"
#include "alphabet.h"

class Alphabet;

class Chain {
  public:
    Chain() = default;
    Chain(std::string chain);
    Chain(std::vector<Symbol> chain);
    ~Chain();

    std::vector<Symbol> getChain();
    
  private:
    Alphabet* alphabet_;
    std::vector<Symbol> chain_;
};

#endif
