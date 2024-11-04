// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 05/11/2024
// Archivo main.cc: 
//          Contiene la función main del proyecto que usa la clase Grammar
//          para convertir una gramática a FNC
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          31/10/2024 - Creación (primera versión) del código

#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
#include "grammar.h"

/** @brief Main function
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
int main(int argc, char* argv[]) {
  if (CheckParameters(argc, argv)) {
    std::string input_file = argv[1];
    std::ofstream output_file{std::string(argv[2])};
    if (CheckFile(input_file)) {
      Grammar standard_grammar{input_file};
      //standard_grammar.Print();
      if (!standard_grammar.CheckIfEmptyProductions() && !standard_grammar.CheckIfUnitaryProductions()) {
        standard_grammar.ConvertToCNF();
        //standard_grammar.Print();
        output_file << standard_grammar;
        return 0;
      }
      else {
        std::cerr << "No se puede producir una gramática en Forma Normal de Chomsky" << std::endl;
        return 1;
      }
    }
    else {
      return 1;
    }
  }
  return 1;
}