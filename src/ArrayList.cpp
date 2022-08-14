/** 
* @file ArrayList.cpp
* @description istenilen faktöriyeli istenilen şekilde hesaplar
* @course 1. Öğretim A Grubu
* @assignment 1.ödev
* @date 03.08.2022
* @author Sami Çağlar Acar
*/
#include <iostream>
#include "ArrayList.hpp"


    ArrayList:: ArrayList()
    {
        length = 0;
        capacity = 0;
        items = NULL;
    }

    void ArrayList:: reserve(int newCapacity)
    {
        if (capacity >= newCapacity) return;
        int* tmp = new int[newCapacity];
        for (int j = 0; j < length; j++) tmp[j] = items[j];
        if (items != NULL) delete[] items;
        items = tmp;
        capacity = newCapacity;
    }
    int ArrayList::  size()  const
    {
        return  length;
    }

   
    const int& ArrayList:: elementAt(int i) const
    {
        if (i < 0 || i >= length) throw "No Such Element";
        return items[i];
    }

    void ArrayList:: add(const int& item)
    {
        insert(length, item);
    }
    void ArrayList:: insert(int i, const int& item)
    {
        if (i<0 || i>length) throw "Index Out Of Bound";
        if (length >= capacity) {
            reserve(std::max(1, 2 * capacity));
        }
        for (int j = length - 1; j >= i; j--) items[j + 1] = items[j];
        items[i] = item;
        length++;
    }
	int* ArrayList:: getItems() {
        return items;
    }  
	void ArrayList:: set(int i, int y) {
        items[i] = y;
    }    
    ArrayList:: ~ArrayList()
    {
        if (items != NULL) delete[] items;
    }
