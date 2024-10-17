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

class Chain {
  public:
    Chain(std::string chain);
    Chain(std::vector<std::string> chain);
    ~Chain();

    std::vector<std::string> getChain();
    
  private:
    std::vector<std::string> chain_;
};

#endif
