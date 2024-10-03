// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones regulares
// Autor: Aarón Ramírez Valencia
// Correo: alu0101438238@ull.edu.es
// Fecha: 03/10/2024
// Archivo code_analyzer.cc: 
//          Contiene la implementacion de la clase Code_Analyzer.
// Referencias:
//          Enlaces de interés
// Historial de revisiones
//          03/10/2024 - Creación (primera versión) del código  

#include "code_analyzer.h"

/**
  * @brief Set the program_ object.
  * @param program A const string reference.
  */
void Code_Analyzer::Set_Program(const std::string& program) {
  program_ = program;
}

/**
  * @brief Get the program_ object.
  * @return The program_ value.
  */
std::string Code_Analyzer::Get_Program() const {
  return program_;
}

/**
  * @brief Construct a new Code_Analyzer object.
  * @param program The program to analyze.
  */
Code_Analyzer::Code_Analyzer(std::string program) {
  std::ifstream infile(program);
  Set_Program(program);
  std::string target;
  description_ = Comment (0, "No description");
  main_ = false;
  while (getline(infile, target)) {
    text_.push_back(target);
    if (regex_search(target, kComment) == true) {
      int found = target.find_first_of("//");
      Comment new_comment(text_.size(), target.substr(found));
      comments_.push_back(new_comment);
    } else if (regex_search(target, kMultiCommentStart) == true) {
      std::string string;
      int start = text_.size();
      while (regex_search(target, kMultiCommentFinish) == false) {
        string+= "\n" + target;
        getline(infile, target);
        text_.push_back(target);
      }
      string+= "\n" + target;
      int found = string.find("/*");
      string = string.substr(found);
      found = string.find("*/");
      Comment new_comment(start, text_.size(), string.substr(0, found + 2));
      comments_.push_back(new_comment);
      if (start == 1) {
        description_ = new_comment;
      }
    }

    if (regex_search(target, kSearchLoop) == true) {
      Statement new_statement(text_.size(), target);
      statements_.push_back(new_statement);
    }
    
    if (regex_search(target, kMainSearch) == true) {
      main_ = true;
    } else if (regex_search(target, kIntDoubleSearch) == true) {
      if (!regex_search(target, kForLoopSearch)) {  // Verificar si la declaración esta dentro de un bucle for
        Variable new_variable(text_.size(), target);
        variables_.push_back(new_variable);
      }
    }
  }
  infile.close();
}

/**
  * @brief Save the analyzed program to a file.
  * @param file The file to save the program.
  */
void Code_Analyzer::Save(const std::string file) {
  std::ofstream outfile(file);
  outfile << "PROGRAM: " << Get_Program() << std::endl;

  outfile << "DESCRIPTION: " << std::endl << description_;
  outfile << std::endl << std::endl;

  outfile << "VARIABLES: " << std::endl;
  for (int i = 0; i < variables_.size(); ++i) {
    outfile << variables_[i] << std::endl;
  }
  outfile << std::endl;

  outfile << "STATEMENTS: " << std::endl;
  for (int i = 0; i < statements_.size(); ++i) {
    outfile << statements_[i] << std::endl;
  }
  outfile << std::endl;

  outfile << "MAIN: ";
  if (main_) {
    outfile << "True" << std::endl << std::endl;
  }
  else {
    outfile << "False" << std::endl << std::endl;
  }
  outfile << "COMMENTS: " << std::endl;
  for (int i = 0; i < comments_.size(); ++i) {
    if (comments_[i].Get_Text() == description_.Get_Text()) {
      outfile << description_.Get_Lines() << ": DESCRIPTION" << std::endl;

    }
    else {
      outfile << comments_[i] << std::endl;
    }
  }
  outfile.close();
}