// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones regulares
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 03/10/2024
// Archivo .cc: 
//          Contiene la funcion que detecta cuando se realiza un uso incorrecto 
//          del programa y propone un ejemplo de uso con el parametro --help.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          03/10/2024 - Creación (primera versión) del código        


#include "code_analyzer.h"
#include <string>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    if (argc == 2) {
      std::string parameter{argv[1]};
      if (parameter == "--help") {
        std::cout << "El programa se ejecuta de la siguiente manera: " << std::endl;
        std::cout << argv[0] << " factorial.cc factorialscheme.txt" << std::endl;
        std::cout << "factorial.cc -> Programa a analizar" << std::endl;
        std::cout << "factorialscheme.txt -> Fichero de salida" << std::endl;
        exit(EXIT_SUCCESS);
      }
      std::cerr << "Error en el numero de parametros. \nPara mas informacion, escriba el comando: ./p02_languages --help" << std::endl;
      exit(EXIT_FAILURE);
    } else {
      std::cerr << "Este programa necesita 2 parámetros, intente ./p02_languages --help" << std::endl;
      exit(EXIT_FAILURE);
    }
  } else {
    Code_Analyzer file(argv[1]);
    file.Save(argv[2]);
  }
  return 0;
}