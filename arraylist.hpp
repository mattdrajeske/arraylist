
////////////////////////////////////////////////////////
///Matt Drajeske
///CS 1575
///Assignment 2
////////////////////////////////////////////////////////

//#pragma once
#include "arraylist.h"

//constructor for arraylist
template<typename T>
ArrayList<T>::ArrayList(int s, const T& x) {
   this.m_max = s;
   this.m_size = s;
   this.m_data = new T[s];
}

/*
   BIG THREE
*/
//destructor
template<typename T>
ArrayList<T>::~ArrayList() {
   delete[] m_data;
   delete this;
}

//copy constructor
template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy) {
   
}

//operator=
template<typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs) {

}

/*
   OTHER FUNCTIONS
*/
//accessor function for m_size
template<typename T>
int ArrayList<T>::size() const{
   return this.m_size;
}

//accessor function for m_max
template<typename T>
int ArrayList<T>::max() const {
   return this.m_max;
}

//returns first element of the arraylist
template<typename T>
const T& ArrayList<T>::first() const{
   return m_data[0];
}

//overload for [] operator on left side
template<typename T>
T& ArrayList<T>::operator[](int i){

}

//overload for [] operator on right side
template<typename T>
const T& ArrayList<T>::operator[](int i) const {

}

//finds an element in an array
template<typename T>
int ArrayList<T>::find(const T& x) const {
   for (int i = 0; i < this->m_size; i++) {
      if (m_data[i] == x) {
         return i;
      }
   }
}

//clears array, deallocates the data and sets to NULL, m_size and m_max set to 0
template<typename T>
void ArrayList<T>::clear() {

}

template<typename T>
void ArrayList<T>::insert_back(const T& x) {

}

template<typename T>
void ArrayList<T>::insert(const T& x, int i) {

}

template<typename T>
void ArrayList<T>::remove(int i) {

}

template<typename T>
void ArrayList<T>::swap(int i, int k) {

}

template<typename T>
void ArrayList<T>::append(const ArrayList<T>& alist) {

}

template<typename T>
void ArrayList<T>::reverse() {

}

