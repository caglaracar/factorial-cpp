/** 
* @file factorial.hpp
* @description istenilen faktöriyeli istenilen şekilde hesaplar
* @course 1. Öğretim A Grubu
* @assignment 1.ödev
* @date 03.08.2022
* @author Sami Çağlar Acar
*/
#include "ArrayList.hpp"
#include <fstream>
#include <string>
#include <string.h>

#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP
using namespace std;

class factorial{
public:
    int scaleDigit(int sayi);       
    int scaleDigitSumFunc(int sayi);       
    void printFile();
    string myArrayToString(ArrayList* sayi); 
    ArrayList* calculateFactorial(int range);
};
#endif 