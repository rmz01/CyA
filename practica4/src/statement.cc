// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones regulares
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 03/10/2024
// Archivo statement.cc: 
//          Contiene la implementacion de la clase Statement.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          03/10/2024 - Creación (primera versión) del código  

#include "statement.h"

/**
  * @brief Set the line_ object
  * @param line A const int reference.
  */
void Statement::Set_Line(const int& line) {
  line_ = line;
}

/**
  * @brief Set the type_ object
  * @param type A const string reference.
  */
void Statement::Set_Type(const std::string& type) {
  type_ = type;
}

/**
  * @brief Get the line_ object
  * @return The line_ value.
  */
int Statement::Get_Line() const {
  return line_;
}

/**
  * @brief Get the type_ object
  * @return The type_ value.
  */
std::string Statement::Get_Type() const {
  return type_;
}

/**
  * @brief Construct a new Statement object.
  * @param line The line of the comment.
  * @param text The text of the comment.
  */
Statement::Statement(const int line, const std::string text) {
  Set_Line(line);
  if (regex_search(text, kSearchFor) == true) {         // Busca si hay un bule "for"
    std::string type = "for";
    Set_Type(type);
  }
  else if (regex_search(text, kSearchWhile) == true) {  // Busca si hay un bucle "while"
    std::string type = "while";
    Set_Type(type);
  }
}

/**
  * @brief Overload of the operator << for the Statement class.
  * @param os The output stream.
  * @param statement The statement object.
  * @return The output stream.
  */
std::ostream& operator<<(std::ostream& os, const Statement& statement) {
  os << "[Lines " << statement.Get_Line() << "] ";
  if (statement.Get_Type() == "for" || statement.Get_Type() == "while") {
    os << "LOOP : " << statement.Get_Type();
  }
  return os;
}