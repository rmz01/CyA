// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 01/10/2022
// Archivo simbolo.h: 
//          Contiene la definición de la clase Simbolo.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          01/10/2022 - Creación (primera versión) del código

#ifndef SIMBOLO_H_
#define SIMBOLO_H_

#include <iostream>
#include <string>

/** Clase Simbolo:
 * Esta clase define el símbolo del cual pertencerá a un alfabeto.
 */
class Simbolo {
 public:
  // constructores
  Simbolo() = default;
  Simbolo(std::string data);

  //Getters & Setters
  std::string getData() const {return data_;}; 
  void setData(std::string data) {data_ = data;}; 

  //sobrecarga operador <<
  friend std::ostream& operator<<(std::ostream &os, const Simbolo &symbol);

  // sobrecarga operador <
  bool operator<(const Simbolo& other) const {
    return data_ < other.data_;
  }

 private:
  std::string data_;
};

#endif