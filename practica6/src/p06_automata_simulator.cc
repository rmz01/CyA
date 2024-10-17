// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo p06_automata_simulator.cc: 
//          Contiene las definiciones de la función de lectura/escritura de 
//          ficheros y gennera el automata y las cadenas para su evaluacion.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

#include <fstream>
#include <vector>
#include "usage.h"
#include "chain.h"
#include "alphabet.h"
#include "state.h"
#include "automaton.h"


int main(int argc, char* argv[]) {
  //funcion que gestiona los errores en la entrada de parametros por linea de comando
  Usage(argc, argv);

  std::ifstream filein1; //primer fichero de entrada
  filein1.open(argv[1], std::ios_base::in); //abrimos el primer fichero de entrada
  std::ifstream filein2; //segundo fichero de entrada
  filein2.open(argv[2], std::ios_base::in); // abrimos el segundo fichero de entrada

  if (!filein1.is_open() || !filein2.is_open()) {
    std::cerr << "Error al abrir los ficheros de entrada." << std::endl;
    return 1;
  } else {
    std::string inputAutomata = argv[1];
    std::string inputStrings = argv[2];
    Automaton automata(inputAutomata, inputStrings);
    filein1.close();
    filein2.close();
  }
  
  return 0;
}

