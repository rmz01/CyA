// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 18/09/2024
// Archivo cadena.h: 
//          Contiene la definición de la clase cadena.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          18/09/2024 - Creación (primera versión) del código

#ifndef CADENA_H_
#define CADENA_H_

#include <iostream>
#include <string>
#include <vector>
#include "alfabeto.h"
#include "simbolo.h"
#include "lenguaje.h"


/** Clase Cadena:
 * Esta clase se usa para separar la cadena de su alfabeto.
 */
class Cadena {
 public:
  // constructores de la clase cadena
  Cadena() = default;
  Cadena(std::string my_string);

  // funciones
  int Longitud();
  Alfabeto alphabet();
  std::vector<Simbolo> Inversa();
  Lenguaje Prefijos();
  Lenguaje Sufijos();

 private:
  Alfabeto alphabet_;
  std::vector<Simbolo> string_;
};

std::ostream& operator<<(std::ostream &os, const std::vector<Simbolo> &vec);

#endif