// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6 : Simulacion de Automatas Finitos
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 17/10/2024
// Archivo usage.h: 
//          Contiene la funcion que decide si el uso es correcto por parte del  
//          que ejecuta el programa y muestra un ejemplo de uso con --help.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          17/10/2024 - Creación (primera versión) del código

#ifndef USAGE_H_
#define USAGE_H_

#include <iostream>
#include <string>

void Usage(int argc, char* argv[]) {
    if(argc == 1) {
      std::cerr << "Número de parametros incorrecto. \nPara mas informacion, escriba el comando: ./p06_automata_simulator --help" << std::endl;
      exit(EXIT_FAILURE);
    }
  if(argc != 3) {
    std::string parameter{argv[1]};

    if(argc == 2) {
      if(parameter == "--help") {
        std::cout << "Modo de empleo: ./p06_automata_simulator input.fa input.txt" << std::endl;
        std::cout << "Programa que dado un automata y una serie de cadenas, muestra si dichas cadenas son aceptadas. " << std::endl;
        exit(EXIT_SUCCESS);
      }
    }
    std::cerr << "Error en el numero de parametros. \nPara mas informacion, escriba el comando: ./p06_automata_simulator --help" << std::endl;
    exit(EXIT_FAILURE);
  }
}

#endif