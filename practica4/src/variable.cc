// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones regulares
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 03/10/2024
// Archivo variable.cc: 
//          Contiene la implementacion de la clase variable.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          03/10/2024 - Creación (primera versión) del código  

#include "variable.h"

/**
  * @brief Set the line_ object
  * @param line A const int reference.
  */
void Variable::Set_Line(const int& line) {
  line_ = line;
}

/**
  * @brief Get the line_ object
  * @ return The line_ value.
  */
int Variable::Get_Line() const {
  return line_;
}

/**
  * @brief Set the type_ object
  * @param type A const string reference.
  */
void Variable::Set_Type(const std::string& type) {
  type_ = type;
}

/**
  * @brief Get the type_ object
  * @return The type_ value.
  */
std::string Variable::Get_Type() const {
  return type_;
}

/**
  * @brief Set the name_ object
  * @param name A const string reference.
  */
void Variable::Set_Name(const std::string& name) {
  name_ = name;
}

/**
  * @brief Get the name_ object
  * @return The name_ value.
  */
std::string Variable::Get_Name() const {
  return name_;
}

/**
  * @brief Set the value_ object
  * @param value A const string reference.
  */
void Variable::Set_Value(const std::string& value) {
  value_ = value;
}

/**
  * @brief Get the value_ object
  * @return The value_ value.
  */
std::string Variable::Get_Value() const {
  return value_;
}

/**
  * @brief Construct a new Variable object.
  * @param line The line of the comment.
  * @param text The text of the comment.
  */
Variable::Variable(int line, std::string text) {
  const std::string SPACE = " ";
  Set_Line(line);
  std::string string = text;
  int found;
  if (regex_search(text, kIntSearch) == true) {     // Busca si el texto coincide con un entero
    std::string type = "INT: ";
    Set_Type(type);
    found = string.find("int");
    string = string.substr(found);
  }
  else {                                            // Si no se tratará de un flotante
    std::string type = "DOUBLE: ";
    Set_Type(type);
    found = string.find("double");
    string = string.substr(found);
  }

  std::smatch match;                                // Sirve para coincidencias en objetos de cadena
  found = string.find_first_of(SPACE);
  string = string.substr(found + 1);
  if (regex_search(string, match, kVSearchName)) {  // Encuentra el nombre de la variable 
    Set_Name(match.str(0));
  }
  found = string.find_first_of("({=;");             // "({=;" Hace referencia a los tipos de inicializacion de variables
  string = string.substr(found);
  is_value_ = false;
  if (regex_search(string, match, kVSearchNumber) == true) {    // Encuentra el valor de la variable y confirma que sea un valor
    Set_Value(match.str(0));
    is_value_ = true;
  }
}

/**
  * @brief Overload of the operator <<
  * @param os The output stream.
  * @param variable The variable to print.
  * @return The output stream.
  */
std::ostream& operator<<(std::ostream& os, const Variable& variable) {
  os << "[Line " << variable.Get_Line() << "] " << variable.Get_Type();
  os << variable.Get_Name();
  if (variable.is_value_) {
    os << " = " << variable.Get_Value();
  }
  return os;
}
