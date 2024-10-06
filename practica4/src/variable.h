// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones regulares
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 03/10/2024
// Archivo variable.h: 
//          Contiene la definicion de la clase variable.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          03/10/2024 - Creación (primera versión) del código  


#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <regex>

/*
  \b: Coincide con un límite de palabra.
  (int|double): Coincide con "int" o "double".
  \s+: Coincide con uno o más espacios en blanco.
  \w+: Coincide con una o más letras, dígitos o guiones bajos (es decir, un identificador de variable).
  \s*: Coincide con cero o más espacios en blanco.
  (=|;): Coincide con un signo igual "=" o un punto y coma ";".
*/
const std::regex kIntDoubleSearch(R"(\b(int|double)\s+\w+\s*(=|;))");

/*
  \b: Coincide con un límite de palabra.
  for: Coincide con la palabra "for".
  \s*: Coincide con cero o más espacios en blanco.
  \(: Coincide con un paréntesis de apertura "(".
*/
const std::regex kForLoopSearch(R"(\bfor\s*\()");

/*
  \s*: Coincide con cero o más espacios en blanco.
  int: Coincide con la palabra "int".
  .*: Coincide con cualquier carácter (excepto saltos de línea) cero o más veces.
*/
const std::regex kIntSearch("\\s*int.*");

/*
  [a-zA-Z0-9_-]+: Coincide con una o más letras (mayúsculas o minúsculas), dígitos, guiones bajos o guiones.
*/
const std::regex kVSearchName("[a-zA-Z0-9_-]+");

/*
  [0-9.]+: Coincide con uno o más dígitos o puntos.
*/
const std::regex kVSearchNumber("[0-9.]+");

// Clase dedicada a almacenar la información de las variables
class Variable {
 public:
  // Constructores
  Variable(int line, std::string text);
  // Variable() : line_(), type_(), name_(), value_() {};

  // Funciones
  int Get_Line() const;                     // Getter de la linea
  void Set_Line(const int& line);           // Setter de la linea

  std::string Get_Type() const;             // Getter del tipo
  void Set_Type(const std::string& type);   // Setter del tipo

  std::string Get_Name() const;             // Getter del nombre
  void Set_Name(const std::string& name);   // Setter del nombre

  std::string Get_Value() const;            // Getter del valor
  void Set_Value(const std::string& value); // Setter del valor

  // Sobrecarga de operator <<
  friend std::ostream& operator<<(std::ostream& os, const Variable& variable);
  
 private:
  int line_;
  std::string type_;
  std::string name_;
  std::string value_;
  bool is_value_;
};

#endif