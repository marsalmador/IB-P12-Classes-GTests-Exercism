/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file encriptar.cc
 * @author: Marlon Eduardo Salazar Amador
 * @date: 12 ene 2021
 * @brief description: Este programa lee 6 fechas escritas en formato dd/mm/aaaa en un archivo de texto dado
 * por el usuario y las copia ordenadas cronologicamente en un nuevo archivo. Para ello, el usuario debe
 * introducir una serie de datos en la forma dada por el comando "./fechas --help"
 * @bug No hay bugs conocidos
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

int main(int argc, char* argv[]){
  if(argc==1){
    std::cout<<std::endl<<"./fechas - Gestion de fechas"<<std::endl;
    std::cout<<"Modo de uso: ./fechas fichero_entrada.txt ";
    std::cout<<"fichero_salida.txt"<<std::endl;
    std::cout<<"Pruebe ./fechas --help para mas informacion"<<std::endl;
    std::cout<<std::endl;
  }
  
  if(argc > 1 && argc < 3 && (strcmp(argv[1], "--help") == 0)){
    std::cout<<std::endl<<"./fechas -- Gestion de fechas"<<std::endl;
    std::cout<<"Modo de uso: ./fechas fichero_entrada.txt ";
    std::cout<<"fichero_salida.txt"<<std::endl;
    std::cout<<"fichero_entrada.txt: Fichero a leer y ordenar"<<std::endl;
    std::cout<<"fichero_salida.txt: FIchero ordenado"<<std::endl;
    std::cout<<std::endl;
  }

  if(argc == 3){

    std::fstream in(argv[1]);
    std::ofstream out(argv[2]);
    std::string s;
    int i = 0;
    while(getline(in, s)){
    std::string dia_string = s.substr(0,2);
    int dia_ = std::atoi(dia_string.c_str());
    std::string mes_string = s.substr(3,2);
    int mes_ = std::atoi(mes_string.c_str());
    std::string ano_string = s.substr(6,4);
    int ano_ = std::atoi(ano_string.c_str());
    Fecha arr[6];
    arr[i] = {dia_, mes_, ano_};
    i++;
    if(i==6){
      int n = sizeof(arr)/sizeof(arr[0]);
      ordenarFechas(arr, n);
      for(int j=0; j<n; j++){
        out << arr[j].dia << " " << arr[j].mes << " " << arr[j].ano << " " << "\n";
      }
      return 0;
    }
    }
  }
}
