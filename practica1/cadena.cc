// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
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
#include "cadena.h"

// Constructor de la clase Cadena
Cadena::Cadena(std::string my_string) {

  // Buscar si hay "espacios" en la frase
  const char SPACE = ' ';
  int count{0};
  for(unsigned i = 0; i < my_string.length(); i++) {
    if(my_string[i] == SPACE) {
      count++;
    }
  }

  // Caso 1: Incluya Alfabeto
  if(count > 0) {
    //cadena
    for(unsigned i = my_string.find_last_of(SPACE) + 1; i < my_string.length(); i++) {
      string_ += my_string[i];
    }
    //alfabeto
    for(unsigned i = 0; i < my_string.find_last_of(SPACE); i++) {
      if(my_string[i] != SPACE && my_string[i+1] == SPACE) {
        Simbolo aux;
        std::string aux_string{my_string[i]};
        aux.setData(aux_string);
        alphabet_.add(aux);
      }
    }
  }

  // Caso 2: No incluya Alfabeto, sino solo la cadena
  else {
    for(unsigned i = 0; i < my_string.length(); i++) {
      //Alfabeto
      Simbolo aux;
      std::string aux_string{my_string[i]};
      aux.setData(aux_string);

      if(alphabet_.verify(aux) == false) {
        alphabet_.add(aux);
      }
      //Cadena
      string_+= my_string[i];
    }
  }

  // Verificar que la cadena pertenece a su alfabeto;
  for(unsigned i = 0; i < string_.length(); i++) {
    Simbolo aux;
    std::string aux_string{string_[i]};
    aux.setData(aux_string);
    if(alphabet_.verify(aux) == false) {
      std::cerr << "La cadena <<" << string_ << ">> no pertenece al alfabeto dado: " << alphabet_ <<  std::endl;
      exit(EXIT_SUCCESS);
    } 
  }
}

// Funcion que devuelve el alfabeto de la cadena
Alfabeto Cadena::alphabet() {
  return alphabet_;
}

//Función que devuelve la longitud de la cadena
int Cadena::Longitud() {
  return string_.length();
}

//Función que devuelve la cadena en orden inverso
std::string Cadena::Inversa() {
  std::string aux;
  for(int i = string_.length() - 1; i >= 0; i--) {
    aux = aux.append(string_.substr(i, 1)); 
  }
  return aux;
}

//Función que calcula los prefijos de la cadena
std::string Cadena::Prefijos() {
  const std::string SPACE = " ";
  std::string aux = "& ";
  unsigned count{1};

  while(count <= string_.length()) {
    for(unsigned i = 0; i < count; i++) {
      aux += string_[i];
    }
    aux += SPACE;
    count++;
  }
  return aux;
}

//Función que calcula los sufijos de la cadena
std::string Cadena::Sufijos() {
  const std::string SPACE = " ";
  std::string out = "& ";
  for(unsigned i = 1; i <= string_.length(); i++) {

    std::string aux;
    for(unsigned j = 0; j < i; j++) {
      aux += string_[string_.length() - 1 - j];
    }

    std::string aux_2;

    for(unsigned j = aux.length(); j > 0; j--){
      aux_2 += aux.substr(j - 1, 1);
    }

    out += aux_2 + SPACE;
  }
  return out;
}