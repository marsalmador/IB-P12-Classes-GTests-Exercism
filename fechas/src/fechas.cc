/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file fechas.cc
 * @author: Marlon Eduardo Salazar Amador
 * @date: 12 ene 2021
 * @brief description: This program reads 6 dates written in dd/mm/yyyy format into
 * a text file given by the user and copies them chronologically into a new file.
 * To do this, the user must enter a series of data in the form given by the
 * "./dates --help" command
 * @bug No known bugs
 * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
 */

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "fecha.h"
#include "fecha.cc"

/**
 * If the user only types "./dates" this small program guide will be displayed.
 */
int main(int argc, char* argv[]){
  if(argc==1){
    std::cout<<std::endl<<"./fechas - Gestion de fechas"<<std::endl;
    std::cout<<"Modo de uso: ./fechas fichero_entrada.txt ";
    std::cout<<"fichero_salida.txt"<<std::endl;
    std::cout<<"Pruebe ./fechas --help para mas informacion"<<std::endl;
    std::cout<<std::endl;
  }
/**
 * If the user types "./dates --help " this guide will be displayed.
 */
  if(argc > 1 && argc < 3 && (strcmp(argv[1], "--help") == 0)){
    std::cout<<std::endl<<"./fechas -- Gestion de fechas"<<std::endl;
    std::cout<<"Modo de uso: ./fechas fichero_entrada.txt ";
    std::cout<<"fichero_salida.txt"<<std::endl;
    std::cout<<"fichero_entrada.txt: Fichero a leer y ordenar"<<std::endl;
    std::cout<<"fichero_salida.txt: FIchero ordenado"<<std::endl;
    std::cout<<std::endl;
  }
/**
 * If the user types "./dates" and two text files names,
 it will start the main function of the program.
 */
  if(argc == 3){
   /**
    * The two text files are opened and the lines of the first one are read.
    */
    std::fstream in(argv[1]);
    std::ofstream out(argv[2]);
    std::string s;
    int i = 0;
    while(getline(in, s)){
  /**
    * The program gets the day, month and year of the dates by using "substr()"
    * and puts them in the array of the class Fecha
    */
    std::string dia_string = s.substr(0,2);
    int dia_array = std::atoi(dia_string.c_str());
    std::string mes_string = s.substr(3,2);
    int mes_array = std::atoi(mes_string.c_str());
    std::string ano_string = s.substr(6,4);
    int ano_array = std::atoi(ano_string.c_str());
    Fecha array_fechas[6];
    array_fechas[i] = {dia_array, mes_array, ano_array};
    i++;
   /**
    * When the last iteration ends, the program sorts the dates and puts them
    * in the second text file given
    */
    if(i==6){
      int numero_elementos_array = sizeof(array_fechas)/sizeof(array_fechas[0]);
      ordenarFechas(array_fechas, numero_elementos_array);
      for(int j=0; j<numero_elementos_array; j++){
        out << array_fechas[j].dia << " " << array_fechas[j].mes << " " << array_fechas[j].ano << " " << "\n";
      }
      return 0;
    }
    }
  }
}
