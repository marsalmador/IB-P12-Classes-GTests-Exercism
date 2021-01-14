#include <iostream>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**Pre: anyo >= 1600
 *Post: Devuelve <true> si y solo si <anyo> es un año
 *bisiesto
 */
bool esBisiesto (const Fecha &fecha){
 //Un año es bisiesto si es múltiplo de 400 o, siendo
 //múltiplo de 4, no lo es de 100. En caso contrario
 //no es bisiesto
 return(fecha.ano % 4 == 0 && fecha.ano % 100 != 0)||(fecha.ano % 400 == 0);
}

bool comparar(const Fecha &fecha1, const Fecha &fecha2){
  if(fecha1.ano < fecha2.ano){
    return true;
  }
  if(fecha1.ano == fecha2.ano && fecha1.mes < fecha2.mes){
    return true;
  }
  if(fecha1.ano == fecha2.ano && fecha1.mes == fecha2.mes && fecha1.dia < fecha2.dia){
    return true;
  }
  return false;
}
void ordenarFechas(Fecha arr[], int n){
  std::sort(arr, arr+n, comparar);
}
