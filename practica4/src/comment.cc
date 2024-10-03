// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones regulares
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 03/10/2024
// Archivo comment.cc: 
//          Contiene la implementacion de la clase comment.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          03/10/2024 - Creación (primera versión) del código  

#include "comment.h"

/**
  * @brief Set the start_ object
  * @param start A const int reference.
  */
void Comment::Set_Start(const int& start) {
  start_ = start;
}

/**
  * @brief Get the start_ object.
  * @return The start_ value.
  */
int Comment::Get_Start() const {
  return start_;
}

/**
  * @brief Set the finish_ object
  * @param start A const int reference.
  */
void Comment::Set_Finish(const int& finish) {
  finish_ = finish;
}

/**
  * @brief Get the finish_ object
  * @return The finish_ value.
  */
int Comment::Get_Finish() const {
  return finish_;
}

/**
  * @brief Get the text_ object
  * @return The text_ value.
  */
std::string Comment::Get_Text() const {
  return text_;
}

/**
  * @brief Construct a new Comment object with a range of lines.
  * @param start The start of the comment.
  * @param finish The finish of the comment.
  * @param text The text of the comment.
  */
Comment::Comment(const int start, const int finish, const std::string text) {
  Set_Start(start);
  Set_Finish(finish);
  text_ = text;
}

/**
  * @brief Construct a new Comment objec with a single line.
  * @param line The line of the comment.
  * @param comment The text of the comment.
  */
Comment::Comment(const int line, const std::string comment) {
  Set_Start(line);
  Set_Finish(line);
  text_ = comment;
}

/**
  * @brief Get the lines of the comment.
  * @return The lines of the comment.
  */
std::string Comment::Get_Lines() const {
  std::string string;
  // Monolinea
  if (Get_Start() == Get_Finish()) {
    string += "[Line " + std::to_string(finish_) + "]";
  }
  // Multilinea
  else {
    string += "[Lines " + std::to_string(start_) + "-";
    string += std::to_string(finish_) + "]";
  }
  return string;
}

/**
  * @brief Overload the operator << to print the comment.
  * @param os The output stream.
  * @param comment The comment to print.
  * @return The output stream.
  */
std::ostream& operator<<(std::ostream& os, const Comment& comment) {
  if (comment.Get_Start() == comment.Get_Finish() && comment.Get_Start() == 0) {
    os << comment.Get_Text();
  }
  else if (comment.Get_Start() == comment.Get_Finish()) {
    os << "[Line " << comment.Get_Start() << "] " << comment.Get_Text();
  }
  else {
    os << "[Lines " << comment.Get_Start() << "-" << comment.Get_Finish()  << "]: ";
    os << comment.Get_Text();
  }
  return os;
}