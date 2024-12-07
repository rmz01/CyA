// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos Voraces (Greedy). Euclidean Minimum Spanning Tree
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 10/12/2024
// Archivo: main.cpp
// Descripción: Programa que genera un EMST a partir de una nube de puntos

#include <iostream>
#include <fstream>
#include <iomanip>
#include "point_set.h"
#include "sub_tree.h"
#include "point_types.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Modo de empleo: " << argv[0] << " [-d] archivo_entrada" << std::endl;
    exit(EXIT_FAILURE);
  }

  bool generateDot = false;
  std::string inputFileName;

  // Verificar la opción -d
  if (argc == 3 && std::string(argv[1]) == "-d") {
    generateDot = true;
    inputFileName = argv[2];
  } 
  else if (argc == 2) {
    inputFileName = argv[1];
  }

  // Crear un conjunto de puntos a partir del fichero
  ifstream file(inputFileName);
  int num_puntos;
  file >> num_puntos;

  // Crear el vector de puntos
  CyA::point_vector points;
  for (int i = 0; i < num_puntos; i++) {
    double x, y;
    file >> x >> y;
    points.push_back({x, y});
  }
  file.close();

  EMST::point_set pointSet(points);
  
  // Calcular el Árbol de Expansión Mínima
  pointSet.EMST();

  // Obtener información del árbol
  const CyA::tree& emstTree = pointSet.get_tree();
  const CyA::point_vector& originalPoints = pointSet.get_points();
  const double cost = pointSet.get_cost();

  // Imprimir resultados
  std::cout << "Conjunto de puntos original:\n";
  for (const auto& point : originalPoints) {
    std::cout << "(" << std::setw(4) << point.first << ", " << std::setw(4) << point.second << ")\n";
  }

  std::cout << "\nÁrbol de Expansión Mínima:\n";
  for (const auto& arc : emstTree) {
    std::cout << "(" << std::setw(4) << arc.first.first << ", " << std::setw(4) << arc.first.second << ") -> ("
              << std::setw(4) << arc.second.first << ", " << std::setw(4) << arc.second.second << ")\n";
  }

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "\nCosto total del árbol: " << cost << std::endl;

  // Generar el archivo .dot si el usuario lo solicita
  if (generateDot) {
    pointSet.write_dot_file("emst_tree.dot");
  }

  return 0;
}