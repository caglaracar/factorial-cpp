/** 
* @file main.cpp
* @description istenilen faktöriyeli istenilen şekilde hesaplar
* @course 1. Öğretim A Grubu
* @assignment 1.ödev
* @date 03.08.2022
* @author Sami Çağlar Acar
*/
#include <iostream>
#include <fstream>
#include "factorial.hpp"
#include "ArrayList.hpp"
#include <string>



using namespace std;

int main() {
    
  int number=0;
    cout<<"Enter the number of factorials you want to be calculated on the screen: "<<endl;
    cin>>number;
    
    factorial *calculateFactorial=new factorial();
    
    ArrayList* first = calculateFactorial->calculateFactorial(number);
    
    string myString=calculateFactorial->myArrayToString(first);
    
    ofstream file("./doc/Sonuc.txt");
    file << myString;
    file.close();
    delete first;

  
 

   


}