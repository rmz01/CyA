#include <iostream>
#include "symbol.h"

// sobrecarga operador <<
std::ostream& operator<<(std::ostream &os, const Symbol &simbolo){
  os << simbolo.getData();
  return os;
}