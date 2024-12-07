// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos Voraces (Greedy). Euclidean Minimum Spanning Tree
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 10/12/2024
// Archivo: sub_tree.hpp
// Descripción: Declaración de la clase sub_tree

#pragma once

#include <iostream>
#include <cmath>
#include "point_types.h"

namespace EMST {
  class sub_tree {
    private:
    CyA::tree arcs_; // Almacena los arcos del árbol
    CyA::point_collection points_; // Almacena los puntos del sub-árbol
    double cost_; // Almacena el costo asociado al árbol

    public:
    sub_tree(); // Constructor por defecto
    ~sub_tree(); // Destructor por defecto

    void add_arc(const CyA::arc& a); // Agregar un arco al sub-árbol
    void add_point(const CyA::point& p); // Agregar un punto al sub-árbol
    bool contains(const CyA::point& p) const; // Verificar si un punto está contenido en el sub-árbol
    void merge(const sub_tree& st, const CyA::weigthed_arc& a); // Fusionar el sub-árbol actual con otro

    const CyA::tree& get_arcs() const; // Obtener los arcos del sub-árbol
    double get_cost() const; // Obtener el costo del sub-árbol
  };
  typedef std::vector<sub_tree> sub_tree_vector; // Almacena objetos de la clase sub_tree
}