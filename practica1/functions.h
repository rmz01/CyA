// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 01/10/2022
// Archivo functions.h: 
//          Contiene las definiciones de la función de lectura/escritura de 
//          ficheros y la función para el --help por línea de comandos.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          01/10/2022 - Creación (primera versión) del código


#include <iostream>

const std::string kHelpText = "./p01_strings -- Símbolos, Alfabetos y Cadenas \n\
  Como usar: ./p01_strings fichero_entrada fichero_salida opcode. \n \n\
	fichero_entrada: Fichero que debe proporcionar un alfabeto y a su vez una cadena con la que operar. \n\
  fichero_salida:  Fichero que debe dar los resultados de la operación realizada. \n\
  opcode: Función a realizar (1)Longitud, (2)Inversa, (3)Prefijos, (4)Sufijos, (5)Subcadenas. \n";

void Usage(int argc, char *argv[]);
void Options(const std::string input_file, const std::string output_file, const int opcode);