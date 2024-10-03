/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Informatica Basica
 *
 * @brief Ejercicios de programacion
 * Version 1: Funcion factorial
 *
 * @see https :// github . com / IB -2023 -2024/ IB - class - code - examples /
 */
11
12 # include < iostream >
13 # include < cassert >
14
15 // Returns the factorial of the argument
16 int Factorial ( int number ) {
17 switch ( number ) {
18 case 0:
19 case 1:
20 return 1;
21 default :
22 int factorial = 1;
23 for ( int i = 1; i <= number ; ++ i ) {
24 factorial *= i ;
25 }
26 return factorial ;
27 }
28 }