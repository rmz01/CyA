#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <iostream>

const std::string kHelpText = "./Grammar2CNF input.gra output.gra\n\n\
---ACLARACIONES---\n\n\
Por como está diseñado el programa se tendrá que tener en cuenta las siguientes indicaciones:\n\n\
  - Poner en primer lugar el número de terminales que tendrá el programa, seguido de esto, los\
    terminales puestos de uno en uno por cada linea del fichero de texto, estos terminales tendrán\
    que ser letras del alfabeto latino en minúscula según indica el convenio de notación de gramáticas.\n\n\
  - Seguido de los terminales, irá el número de no-terminales, puestos de la misma forma que los terminales,\
    solo que los no-terminales deberán ser letras del alfabeto latino en mayúscula según indica el convenio\
    de notación de gramáticas.\n\n\
  - Por último, irá el número de producciones que tiene la gramática, cada una separada por lineas y puestas\
    de manera que al principio de la linea irá el no-terminal al que pertenece dicha produccion, una separación\
    por espacio, y finalmente la produccion de ese no-terminal.";

bool CheckParameters(int argc, char* argv[]);
bool CheckFile(const std::string& input_file);
void ErrorExit(const std::string& message);

#endif // FUNCTIONS_H