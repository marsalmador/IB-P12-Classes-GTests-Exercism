#include <iostream>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Every year that is exactly divisible by four is a leap year, except for
 * years that are exactly divisible by 100, but these centurial years are
 * leap years if they are exactly divisible by 400. That's what the
 * function checks.
 */
bool esBisiesto (const Fecha &fecha){

 return(fecha.ano % 4 == 0 && fecha.ano % 100 != 0)||(fecha.ano % 400 == 0);
}

/**
 * This function gets each part of the dates given and compares them with
 * logical operators.
 */
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

/**
 * By using "sort" we sort the dates in the array given. We use "arr+n"
 * because we need to give the beginning and the end of the array to
 * sort that interval, and "n" is the total number of elements the
 * array has.
 */
void ordenarFechas(Fecha array_fechas[], int numero_elementos_array){
  std::sort(array_fechas, array_fechas+numero_elementos_array, comparar);
}
