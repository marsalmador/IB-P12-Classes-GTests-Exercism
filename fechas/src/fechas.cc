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
        out << arr[j].d << " " << arr[j].m << " " << arr[j].a << " " << "\n";
      }
      return 0;
    }
    }
  }
}
