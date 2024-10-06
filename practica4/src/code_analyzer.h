// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones regulares
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 03/10/2024
// Archivo code_analyzer.h: 
//          Contiene la definición de la clase Code_Analyzer
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          03/10/2024 - Creación (primera versión) del código  

#ifndef CODE_ANALYZER_H
#define CODE_ANALYZER_H

#include <fstream>
#include <iostream>
#include <regex>
#include "comment.h"
#include "variable.h"
#include "statement.h"

/*
  Coincide con los caracteres "//" que indican el inicio de un comentario de una sola línea en C++.
  .*: Coincide con cualquier carácter (excepto saltos de línea) cero o más veces.
*/
const std::regex kComment("//.*");

/*
  /\\*.*: Coincide con los caracteres "/*" que indican el inicio de un comentario de varias líneas en C++.
  : Coincide con cualquier carácter (excepto saltos de línea) cero o más veces.
*/
const std::regex kMultiCommentStart("/\\*.*");

/*
  Coincide con cualquier carácter (excepto saltos de línea) cero o más veces.
*/
const std::regex kMultiCommentFinish(".*\\*/");

/*
  int main: Coincide con la declaración de la función principal "int main".
*/
const std::regex kMainSearch("int main");

// Clase dedicada a analizar el archivo de entrada
class Code_Analyzer {
 public:
  // Constructor
  Code_Analyzer(std::string program);

  // Funciones
  std::string Get_Program() const;                // Getter del programa
  void Set_Program(const std::string& program);   // Setter del programa
  void Save(const std::string file);              // Guarda el programa en un archivo


 private:
  std::vector<std::string> text_;
  std::string program_;
  Comment description_;
  std::vector<Variable> variables_;
  std::vector<Statement> statements_;
  std::vector<Comment> comments_;
  bool main_;
};

#endif