#include <iostream>
using namespace std;

template <class T>
class matrix{
  T *v;
  int nRows,nCols;
public:
  matrix();
  matrix(int nrows, int ncols);
  matrix(matrix<T> & arrayobj);
  matrix<T> & operator=(matrix& rhs);
  int rows() const;
  int columns() const;
  T & operator()(int i, int j) const;
  T * operator()(int i) const;
  ~matrix();
};

template <class T>
ostream & operator<< (ostream & o, matrix<T> &a);

template <class T>
istream & operator>> (istream & i, matrix<T> &a);


#ifndef MATRIX
#define MATRIX

template <class T>
matrix<T>::matrix(){v=NULL; nRows = nCols = 0;}

template <class T>
matrix<T>::matrix(matrix<T> & arrayobj){
  nRows = arrayobj.nRows; 
  nCols = arrayobj.nCols;
  v = new T[nRows*nCols];
  for(int i=0; i<nRows*nCols; i++) v[i] = arrayobj.v[i];
}

template <class T>
matrix<T>::matrix(int nrows, int ncols){
  nRows = nrows;
  nCols = ncols;
  v = new T[nRows*nCols];
}

template <class T>
matrix<T> & matrix<T>::operator=(matrix& rhs){
  if(this != &rhs){
    nRows = rhs.nRows;
    nCols = rhs.nCols;
    T * newv = new T[nRows*nCols];
    delete[] v;
    v = newv;
    for(int i=0; i<nRows*nCols; i++) v[i] = rhs.v[i];
  }
  return *this;
}

template <class T>
matrix<T>::~matrix(){
  delete[] v;
}

template <class T>
int matrix<T>::rows()const {return nRows;}

template <class T>
int matrix<T>::columns()const {return nCols;}

template <class T>
T & matrix<T>::operator()(int i, int j) const {
  if(i >= nRows || i < 0 || j >= nCols || j < 0){
    cout << "Out of bounds indices ("<< i <<", "<<j<<
      ").  Max allowed ("<< nRows-1<<", "<<nCols-1<<").\n";
    throw 100;
  }
  return v[i*nCols+j];
}

template <class T>
T * matrix<T>::operator()(int i) const {
  if(i >= nRows || i < 0){
    cout << "Out of bounds indices ("<< i <<", "<< " * "<<
      ").  Max allowed ("<< nRows-1<<", "<<nCols-1<<").\n";
  }
  return &v[i*nCols];
}

template <class T>
ostream & operator<< (ostream & o, matrix<T> &a) {
  for(int i=0; i<a.rows(); i++){
    for(int j=0; j<a.columns(); j++)
      o << a(i,j) << " ";
    o << endl;
  }
  return o;
}

template <class T>
istream & operator>> (istream & is, matrix<T> & a){
  for(int i=0; i<a.rows(); i++){
    for(int j=0; j<a.columns(); j++)
      is >> a(i,j);
  }
  return is;
}

#endif
