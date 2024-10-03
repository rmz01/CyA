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

const std::regex kSearchLoop("for|while \\s*?(.+)");
const std::regex kSearchFor("for\\s*?(.+)");
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