/** 
* @file factorial.cpp
* @description istenilen faktöriyeli istenilen şekilde hesaplar
* @course 1. Öğretim A Grubu
* @assignment 1.ödev
* @date 03.08.2022
* @author Sami Çağlar Acar
*/
#include <iostream>
#include <fstream>
#include "ArrayList.hpp"
#include "factorial.hpp"
#include <string>


using namespace std;

    //get number of digit fonksiyonu verilen integer sayının basamak toplamlarını integer olarak döndürür
    int factorial:: scaleDigit(int number) {
       int scale = 0;
        if (number == 0){     
          return 1;
        }           
        for(int i=0; 0<number; i++){
            scale++;
            number /= 10;
          
        }
        
         return scale;
        }
        
    
    // scaleDigitSumFunc function verilen sayının basamalarının toplamını integer olarak döndürür 
    int factorial:: scaleDigitSumFunc(int number) {
        int sum = 0;
        for (int i = 0; 0<number; i++)
        {
            sum += number % 10;
            number /= 10;
        }    
        return sum;
    }   

    //gelen arraylisti stringe dönüştürür bunu yaparken boşlukları sıfır ile doldurur
    string factorial:: myArrayToString(ArrayList* firstArray){
           string firstString = ""; 
            for (int i = 0; i < firstArray->size(); i++)
    {
        int added = firstArray->elementAt(i);
        if (scaleDigit(added) == 4)
            firstString += to_string(added);
        if (scaleDigit(added) == 3) {
            firstString += "0";
            firstString += to_string(added);

        }
        if (scaleDigit(added) == 2) {
            firstString += "00";
            firstString += to_string(added);
        }
        if (scaleDigit(added) == 1) {
            firstString += "000";
            firstString += to_string(added);
        }
    } 
    while (true) {
        if (firstString.at(0) == '0') {
            firstString = firstString.substr(1);

        }        
        else 
            break;
    }
        return firstString;
      }

    //* ana fonksiyonumuz. Faktoriyel hesapalmasını yapan fonksiyondur.
    ArrayList* factorial:: calculateFactorial(int range) {
        ArrayList* myList = new ArrayList();
        myList->add(1);
        int tmpResult = 0;
        
        for (int i = 1; i <= range; i++) {            
            int digit = scaleDigitSumFunc(i);
            ArrayList* carry = new ArrayList();
    //faktöriyel hesaplarken taşan sayıları 4 basamaklı olacak şekilde ayırmaya yarar.
            for (int j = 0; j < myList->size(); j++) {
                tmpResult = myList->elementAt(j) * digit;
                myList->set(j, tmpResult % 10000);
                if (scaleDigit(tmpResult) > 4) {
                    carry->add(tmpResult / 10000);
                }
                else if (scaleDigit(tmpResult) <= 4) {
                    carry->add(0);
                }
            }
            //çarpma işleminde sonra  elde edilen "carrye" göre eklememler yapıyoruz.
            for (int j = carry->size() - 1; j >= 1; j--) {
                int myResult = myList->elementAt(j - 1) + carry->elementAt(j);
                if (myResult > 9999) {
                    carry->set(j - 1, (carry->elementAt(j - 1) + 1));
                    myList->set(j - 1, myResult % 10000);
                }
                else {
                    myList->set(j - 1, myResult);
                }
            }
            
            if (carry->elementAt(0) != 0) {
                myList->insert(0, carry->elementAt(0));
            }
            delete carry;
        }               
        return myList;
    } 

