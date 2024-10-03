// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones regulares
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 03/10/2024
// Archivo comment.h: 
//          Contiene la definicion de la clase Comment.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          03/10/2024 - Creación (primera versión) del código  

#ifndef COMMENT_H
#define COMMENT_h

#include <string>
#include <vector>
#include <fstream>

// Clase dedicada a almacenar los comentarios
class Comment {
 public:
  // Constructores
  Comment(const int start, const int finish, const std::string text);
  Comment(const int line, const std::string text);
  Comment() : start_(), finish_(), text_() {};

  // Funciones
  std::string Get_Lines() const;  // Getter de las lineas
  std::string Get_Text() const;   // Getter del texto completo

  int Get_Start() const;                     // Getter del inicio
  void Set_Start(const int& start);          // Setter del inicio

  int Get_Finish() const;                    // Getter del final
  void Set_Finish(const int& finish);        // Setter del final

  // Sobrecarga de operator <<
  friend std::ostream& operator<<(std::ostream& os, const Comment& comment);

 private:
  int start_;
  int finish_;
  std::string text_;
};

#endif