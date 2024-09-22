// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 18/09/2024
// Archivo functions.h: 
//          Contiene las definiciones de la función de lectura/escritura de 
//          ficheros y la función para el --help por línea de comandos.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          18/09/2024 - Creación (primera versión) del código

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>

const std::string kHelpText = "./cya-P02 -- Símbolos, Alfabetos y Cadenas \n\
  Como usar: ./cya-P02 fichero_entrada fichero_salida opcode. \n \n\
	fichero_entrada: Fichero que debe proporcionar un alfabeto y a su vez una cadena con la que operar. \n\
  fichero_salida:  Fichero que debe dar los resultados de la operación realizada. \n\
  opcode: Función a realizar (1)Alfabeto, (2)Longitud, (3)Inversa, (4)Prefijos, (5)Sufijos. \n";

void Usage(int argc, char *argv[]);
void Options(const std::string input_file, const std::string output_file, const int opcode);

#endif