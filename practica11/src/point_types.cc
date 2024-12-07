// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos Voraces (Greedy). Euclidean Minimum Spanning Tree
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 10/12/2024
// Archivo: point_types.cpp
// Descripción: Implementación de point_types

#include "point_types.h"

#include <iomanip>

// Sobrecarga de los operadores

std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps) {
  os << ps.size() << std::endl;

  for (const CyA::point &p : ps) {
    os << p << std::endl;
  }

  return os;
}

std::ostream& operator<<(std::ostream& os, const CyA::point& p) {
  os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.first << "\t" << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.second;

  return os;
}

std::istream& operator>>(std::istream& is, CyA::point_vector& ps) {
  int n;
  is >> n;

  ps.clear();

  for (int i = 0; i < n; ++i) {
    CyA::point p;
    is >> p;

    ps.push_back(p);
  }

  return is;
}

std::istream& operator>>(std::istream& is, CyA::point& p) {
  is >> p.first >> p.second;

  return is;
}