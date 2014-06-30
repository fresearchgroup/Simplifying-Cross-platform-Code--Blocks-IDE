#include <iostream>
using namespace std;

template <class T>
class array{
  T *v;
  int n;
public:
  array();
  array(int nelts);
  int size();
  T & operator()(int i);
  ~array();
  void print(string header="");
  void read(string instruction="");
  T sum();
  T norm(float normval=2);
};

typedef array<float> FA;

#ifndef ARRAY
#define ARRAY

template <class T>
array<T>::array(){v=NULL; n = 0;}

template <class T>
array<T>::array(int nelts){
  n = nelts;
  v = new T[n];
}

template <class T>
array<T>::~array(){
  //delete[] v;
}

template <class T>
int array<T>::size(){return n;}

template <class T>
T & array<T>::operator()(int i){
  if(i >= n || i < 0){
    cout << "Out of bounds index "<< i <<
      ").  Max allowed "<< n-1<<".\n";
  }
  return v[i];
}

template <class T>
void array<T>::print(string header){
  cout << header;
  for(int i=0; i<n; i++) cout << v[i] << " ";
  cout << endl;
}

template <class T>
void array<T>::read(string instruction){
  cout << instruction;
  for(int i=0; i<n; i++) cin >> v[i];
}

template <class T>
T array<T>::sum(){
  T s = 0;
  for(int i=0; i<n; i++) s += v[i];
  return s;
}

template <class T>
T array<T>::norm(float normval){
  T s = 0;
  for(int i=0; i<n; i++) s += pow(abs(v[i]),normval);
  return pow(s,1/normval);
}

#endif
