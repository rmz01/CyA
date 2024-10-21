#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <iostream>
#include <string>

/** Clase Symbol:
 * Esta clase define el símbolo del cual pertencerá a un alfabeto.
 */
class Symbol {
 public:
  // constructores
  Symbol() = default;
  Symbol(std::string data) : data_(data) {};

  // Getters & Setters
  std::string getData() const {return data_;}; 
  void setData(std::string data) {data_ = data;}; 

  //sobrecarga operador <<
  friend std::ostream& operator<<(std::ostream &os, const Symbol &simbolo);

  // sobrecarga operador <
  bool operator<(const Symbol& other) const {
    return data_ < other.data_;
  }

 private:
  std::string data_;
};

#endif