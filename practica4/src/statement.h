// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones regulares
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 03/10/2024
// Archivo statement.h: 
//          Contiene la definicion de la clase Statement.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          03/10/2024 - Creación (primera versión) del código  

#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <regex>

/*
  for|while: Coincide con la palabra "for" o "while".
  \s*: Coincide con cero o más espacios en blanco.
  (.+): Coincide con cualquier carácter (excepto saltos de línea) una o más veces.
*/
const std::regex kSearchLoop("for|while \\s*?(.+)");

/*
  for: Coincide con la palabra "for".
  \s*: Coincide con cero o más espacios en blanco.
  (.+): Coincide con cualquier carácter (excepto saltos de línea) una o más veces.
*/
const std::regex kSearchFor("for\\s*?(.+)");

/*
  while: Coincide con la palabra "while".
  \s*: Coincide con cero o más espacios en blanco.
  (.+): Coincide con cualquier carácter (excepto saltos de línea) una o más veces.
*/
const std::regex kSearchWhile("while\\s*?(.+)");

// Clase dedicada a almacenar la información de los bucles
class Statement {
 public:
  // Constructores
  Statement(const int line, const std::string text);
  // Statement() : line_(), type_() {};

  // Funciones
  int Get_Line() const;                     // Getter de la linea
  void Set_Line(const int& line);           // Setter de la linea
  std::string Get_Type() const;             // Getter del tipo
  void Set_Type(const std::string& type);   // Setter de la linea

  // Sobrecarga de operator <<
  friend std::ostream& operator<<(std::ostream& os, const Statement& statement);
  
 private:
  int line_;
  std::string type_;
};

#endif