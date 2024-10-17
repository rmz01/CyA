// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo alphabet.h: 
//          Contiene las definicion de la clase alphabet.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

#ifndef __ALPHABET__
#define __ALPHABET__

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include "chain.h"

class Alphabet {
  public:
    Alphabet(); // constructor sin parametros
    Alphabet(std::string alphabet); // constructor al que se le pasa una string

    std::set<std::string>& getSymbols();

    Alphabet& operator=(Alphabet& alfabeto); // sobrecarga operator =
    friend std::ostream& operator<<(std::ostream& os, Alphabet& alfabeto); // sobrecarga operator <<

  private:
    std::set<std::string> symbols_;
};

#endif