#include <iostream>
/**
 * class definition: date class
 */
class Fecha{
  public: //Atributtes
    int dia, mes, ano; 
  public: //Methods
/**
 * It checks if a date is a leap year
 *
 * @param The date to check
 * @return True or False depending on wether the program
 * verifies that the date is a leap year
 */
    bool esBisiesto();
/**
 * It compares two dates and checks if the first date is
 * less than the second one
 *
 * @param The dates to compare
 * @return True or False depending on wether the program
 * verifies that the first date is less than the second 
 * one
 */  
    bool comparar();
/**
 * It sorts the dates within the given array
 *
 * @param The array and the number of elements it has
 * @return The array sorted
 */
    void ordenarFechas();
};
