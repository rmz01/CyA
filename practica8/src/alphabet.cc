#include "alphabet.h"

/** @brief Sobrecarga del operador de extracción para la clase Alphabet
 *  @param[in] out. Flujo de salida
 *  @param[in] alphabet. Objeto de la clase Alphabet que se va a imprimir
 *  @return Devuelve el flujo de salida
 */
std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  for (auto it = alphabet.alphabet_.begin(); it != alphabet.alphabet_.end(); ++it) {
    if (*it != '&') {
      out << *it << std::endl;
    }
  }
  return out;
}

/** @brief Sobrecarga del operador de comparación !=
 *  @param[in] alphabet1. Objeto de la clase Alphabet
 *  @param[in] alphabet2. Objeto de la clase Alphabet
 *  @return Compara los sets de cada alfabeto y retorna si son desiguales o no
 */
bool operator!=(const Alphabet& alphabet1, const Alphabet& alphabet2) {
  return alphabet1.GetSet() != alphabet2.GetSet();
}