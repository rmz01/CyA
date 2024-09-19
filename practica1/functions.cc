// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 18/09/2024
// Archivo functions.cc: 
//          Contiene las definiciones de la función de lectura/escritura de 
//          ficheros y la función para el --help por línea de comandos.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          18/09/2024 - Creación (primera versión) del código
// Bugs:
//          - Repite una vez la última línea del fichero de lectura.
 


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include "functions.h"
#include "cadena.h"

/** Muestra como se debe usar el programa y en el caso de que
 *  no se haga un uso correcto, se hace uso de la función Usage.
 **/

void Usage(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "Modo de uso: " << argv[0] << " fichero_entrada fichero_salida opcode. Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }

  if (argc != 4) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << kHelpText << std::endl;
      exit(EXIT_SUCCESS);
    }
    std::cout << "Modo de uso: " << argv[0] << " fichero_entrada \n\
    fichero_salida opcode. Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/** Funcionamiento principal del programa con los archivos
 *  dados y su respectiva opción
 **/

void Options(const std::string kInputFileName, const std::string kOutputFileName, const int kOpcode) {
  std::ifstream input_file {"./" + kInputFileName};
  if (!input_file) {
    std::cerr << "Error de Archivo: " << kInputFileName << " no se puede abrir." << std::endl;
    exit(EXIT_SUCCESS);
  }

  std::ofstream output_file {"./" + kOutputFileName};
  if (!output_file) {
    std::cerr << "Error de Archivo: " << kOutputFileName << " no se puede abrir." << std::endl;
    exit(EXIT_SUCCESS);
  }

  std::string string;

  while(std::getline(input_file, string)) {
    Cadena chain{string};
    switch (kOpcode) {
      case 1:
        output_file << chain.alphabet() << std::endl;
        break;
      case 2:
        output_file << chain.Longitud() << std::endl;
        break;
      case 3:
        output_file << chain.Inversa() << std::endl;
        break;
      case 4:
        output_file << chain.Prefijos() << std::endl;
        break;
      case 5:
        output_file << chain.Sufijos() << std::endl;
        break;
    }
        
    }

  input_file.close();
  output_file.close();
}