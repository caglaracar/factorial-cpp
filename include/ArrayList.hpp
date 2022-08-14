/** 
* @file ArrayList.hpp
* @description istenilen faktöriyeli istenilen şekilde hesaplar
* @course 1. Öğretim A Grubu
* @assignment 1.ödev
* @date 03.08.2022
* @author Sami Çağlar Acar
*/
#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP


class ArrayList {
private:
    int* items;
    int length;
    int capacity;
    void reserve(int newCapacity);
public:
    ArrayList();   
    int  size()  const;
    int* getItems();
    void set(int i, int y);   
    int indexOf(const int& item) const; 
    const int& elementAt(int i) const;
    void add(const int& item);
    void insert(int i, const int& item);
    ~ArrayList();
    
};
#endif