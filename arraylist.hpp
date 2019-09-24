
////////////////////////////////////////////////////////
///Matt Drajeske
///CS 1575
///Assignment 2
////////////////////////////////////////////////////////

//#pragma once
#include "arraylist.h"

using namespace std;

//constructor for arraylist
template<typename T>
ArrayList<T>::ArrayList(int s, const T& x) {
   m_max = s;
   m_size = s;
   m_data = new T[m_size];
   for (int i = 0; i < m_size; i++{
      m_data[i] = x;
   }
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
   this.m_size = cpy.m_size;
   this.m_max = 
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
   if (i > m_max) {
      cout << "Array index out of bounds" << endl;
      return m_errorobj;
   }
   
   return m_data[i];
}

//overload for [] operator on right side
template<typename T>
const T& ArrayList<T>::operator[](int i) const {
   if (i > m_max) {
      cout << "Array index out of bounds" << endl;
      return m_errorobj;
   }

   return m_data[i];
}

//finds an element in an array
template<typename T>
int ArrayList<T>::find(const T& x) const {
   for (int i = 0; i < m_size; i++) {
      if (m_data[i] == x) {
         return i;
      }
   }
}

//clears array, deallocates the data and sets to NULL, m_size and m_max set to 0
template<typename T>
void ArrayList<T>::clear() {
   /*for (int i = 0; i < m_size; i++) {
      m_data[i] = NULL;
   }*/
   delete[] m_data;
   m_data = NULL;
   m_size = 0;
   m_max = 0;
}

//inserts an element at the end of the list
template<typename T>
void ArrayList<T>::insert_back(const T& x) {

   //new array one size larger than old array
   m_size++;
   T* newarray = new T[m_size];
   m_max++;
   for (int i = 0; i < m_size; i++) {
      if (i == m_size-1) {
         newarray[i] = x;
      }
      else {
         newarray[i] = m_data[i];
      }
   }

   //delete old array
   delete[] m_data;
   m_data = NULL;

   //change the data to match the new array
   m_data = new T[m_size];
   for (int i = 0; i < m_size; i++) {
      m_data[i] = newarray[i];
   }
}

//inserts an element after a specified index
template<typename T>
void ArrayList<T>::insert(const T& x, int i) {

   //new array one size larger than old array
   m_size++;
   T* newarray = new T[m_size];
   m_max++;

   //fill array until index of new element, insert, then keep filling array
   for (int k = 0; k < i; k++) {
      if (k < i) {
         newarray[k] = m_data[k];         
      }
      else if (k == i) {
         newarray[k] = x;
      }
      else {
         newarray[k] = m_data[k - 1];
      }
   }

   //delete old array
   delete[] m_data;
   m_data = NULL;

   //change the data to match the new array
   m_data = new T[m_size];
   for (int i = 0; i < m_size; i++) {
      m_data[i] = newarray[i];
   }
}

//remove an element from an array list
template<typename T>
void ArrayList<T>::remove(int i) {
   
   //new array one size larger than old array
   m_size--;
   T* newarray = new T[m_size];
   m_max--;

   //fill new array
   for (int k = 0; k < m_size; k++) {
      if (k < i) {
         newarray[k] = m_data[k];
      }
      else {
         newarray[k] = m_data[k + 1];
      }
   }
}

//swap the indices of two elements in an array
template<typename T>
void ArrayList<T>::swap(int i, int k) {
   
   //do nothing if k and i are the same
   if (k == i) {
      return;
   }

   //error handling
   if (i > m_size || k > m_size || i < 0 || k < 0) {
      cout << "Array index out of bounds";
      return;
   }

   //holder variables for elements at indices i and k
   T holder_i;
   T holder_k;

   //conditions for if elements at i and k have been found yet
   bool found_i = false;
   bool found_k = false;


   //look for elements at index i and index k
   for (int h = 0; h < max_size; h++) {
      
      //element at index i
      if (h == i) {
         holder_i = m_data[h];
         found_i = true;
      }

      //look for element at index k
      for (int j = 0; j < max_size; j++) {
         if (j == k) {
            holder_k = m_data[j];
            found_k = true;
         }

         //do the swap if both elements have been found
         if (found_i && found_k) {
            m_data[j] = holder_i;
            m_data[h] = holder_k;
         }
      }
   }
}

//add another array onto the end of an existing array
template<typename T>
void ArrayList<T>::append(const ArrayList<T>& alist) {
   
   //holder for old size of array
   int oldsize = m_size;

   //increase m_size and m_max
   m_size = this.m_size + alist.m_size;
   m_max = this.m_max + alist.m_max;

   //make new array of a larger size
   T newarray = new T[m_size];

   //fill new container array
   for (int i = 0; i < m_size; i++) {
      if (i < oldsize) {
         newarray[i] = m_data[i];
      }
      else {
         newarray[i] = alist[i - oldsize];
      }
   }

   //delete old array
   delete[] m_data;
   m_data = NULL;

   //change the data to match the new array
   m_data = new T[m_size];
   for (int i = 0; i < m_size; i++) {
      m_data[i] = newarray[i];
   }

}

//reverse the order of the elements in an array
template<typename T>
void ArrayList<T>::reverse() {
   for (int i = 0; i < m_size/2; i++) {
      m_data[i] = m_data[m_max - i];
   }
}

