// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 18/09/2024
// Archivo cadena.cc: 
//          Contiene la implementación de la clase Cadena y sus funciones.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          18/09/2024 - Creación (primera versión) del código  

#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <algorithm>
#include "cadena.h"
#include "lenguaje.h"

// Constructor de la clase Cadena
Cadena::Cadena(std::string my_string) {
  const char SPACE = ' ';
  int count{0};
  for(unsigned i = 0; i < my_string.length(); i++) {
    // buscar espacios en la cadena
    if(my_string[i] == SPACE) {
      count++;
    }
  }

  // Caso 1: La cadena incluye el alfabeto
  if(count > 0) {
    // Separar la cadena del alfabeto
    for(unsigned i = my_string.find_last_of(SPACE) + 1; i < my_string.length(); i++) {
      Simbolo aux;
      std::string aux_string{my_string[i]};
      aux.setData(aux_string);
      string_.push_back(aux);
    }
    // Crear el alfabeto
    for(unsigned i = 0; i < my_string.find_last_of(SPACE); i++) {
      if(my_string[i] != SPACE && my_string[i + 1] == SPACE) {
        Simbolo aux;
        std::string aux_string{my_string[i]};
        aux.setData(aux_string);
        alphabet_.add(aux);
      }
    }
  } else {  // Caso 2: La cadena no tiene el alfabeto
    for(unsigned i = 0; i < my_string.length(); i++) {
      // Crear el alfabeto
      Simbolo aux;
      std::string aux_string{my_string[i]};
      aux.setData(aux_string);
      if(alphabet_.verify(aux) == false) {
        alphabet_.add(aux);
      }
      // Crear la cadena
      string_.push_back(aux);
    }
  }

  // Verificar que la cadena pertenece al alfabeto
  for(unsigned i = 0; i < string_.size(); i++) {
    if(alphabet_.verify(string_[i]) == false) {
      std::cerr << "La cadena <<";
      for (const auto& simbolo : string_) {
        std::cerr << simbolo.getData();
      }
      std::cerr << ">> no pertenece al alfabeto dado: " << alphabet_ <<  std::endl;
      exit(EXIT_SUCCESS);
    } 
  }
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &os, const std::vector<Simbolo> &vec) {
  for (const auto& simbolo : vec) {
    os << simbolo.getData();
  }
  return os;
}

// Funcion que devuelve el alfabeto de la cadena
Alfabeto Cadena::alphabet() {
  return alphabet_;
}

//Función que devuelve la longitud de la cadena
int Cadena::Longitud() {
  return string_.size();
}

//Función que devuelve la cadena en orden inverso
std::vector<Simbolo> Cadena::Inversa() {
  std::vector<Simbolo> aux;
  for(int i = string_.size() - 1; i >= 0; i--) {
    aux.push_back(string_[i]);
  }
  return aux;
}

//Función que calcula los prefijos de la cadena
Lenguaje Cadena::Prefijos() {
  std::vector<std::vector<Simbolo>> prefijos;

  // Crear un vector con el símbolo '&' y lo agrega
  Simbolo simbolo_vacio;
  simbolo_vacio.setData("&");
  prefijos.push_back({simbolo_vacio});

  for(unsigned count = 1; count <= string_.size(); count++) {
    std::vector<Simbolo> aux;
    for(unsigned i = 0; i < count; i++) {
      aux.push_back(string_[i]);
    }
    prefijos.push_back(aux);
  }
  return prefijos;
}

//Función que calcula los sufijos de la cadena
Lenguaje Cadena::Sufijos() {
  std::vector<std::vector<Simbolo>> sufijos;

  // Crear un vector con el símbolo '&' y lo agrega
  Simbolo simbolo_vacio;
  simbolo_vacio.setData("&");
  sufijos.push_back({simbolo_vacio});

  for(unsigned i = 1; i <= string_.size(); i++) {
    std::vector<Simbolo> aux;
    for(unsigned j = 0; j < i; j++) {
      aux.push_back(string_[string_.size() - 1 - j]);
    }
    std::reverse(aux.begin(), aux.end());
    sufijos.push_back(aux);
  }
  return sufijos;
}