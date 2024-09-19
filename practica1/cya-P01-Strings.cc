// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 18/09/2024
// Archivo cya-P01-Strings.cc: programa cliente.
//          Contiene la función main del proyecto que usa la funcion
//          que realiza el trabajo de leer el fichero de entrada
//          y hacer uso de una de las opciones dadas para escribir su
//          resultado en el fichero de salida.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          18/09/2024 - Creación (primera versión) del código

#include <iostream>
#include "functions.h"
#include "cadena.h"

int main(int argc, char* argv[]) {

  Usage(argc, argv);

  std::string input{argv[1]};
  std::string output{argv[2]};
  std::string opcode{argv[3]};

  const int kOpcode = stoi(opcode);

  Options(input, output, kOpcode);

  return 0;
}