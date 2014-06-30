#include <iostream>
using namespace std;

template <class T>
class a2d{
  T *v;
  int nRows,nCols;
public:
  a2d();
  a2d(int nrows, int ncols);
  a2d(a2d<T> & arrayobj);
  a2d<T> & operator=(a2d& rhs);
  int rows();
  int columns();
  T & operator()(int i, int j);
  T * operator()(int i);
  ~a2d();
};

template <class T>
ostream & operator<< (ostream & o, a2d<T> a);

template <class T>
istream & operator>> (istream & i, a2d<T> a);


#ifndef A2D
#define A2D

template <class T>
a2d<T>::a2d(){v=NULL; nRows = nCols = 0;}

template <class T>
a2d<T>::a2d(a2d<T> & arrayobj){
  nRows = arrayobj.nRows; 
  nCols = arrayobj.nCols;
  v = new T[nRows*nCols];
  for(int i=0; i<nRows*nCols; i++) v[i] = arrayobj.v[i];
}

template <class T>
a2d<T>::a2d(int nrows, int ncols){
  nRows = nrows;
  nCols = ncols;
  v = new T[nRows*nCols];
}

template <class T>
a2d<T> & a2d<T>::operator=(a2d& rhs){
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
a2d<T>::~a2d(){
  delete[] v;
}

template <class T>
int a2d<T>::rows(){return nRows;}

template <class T>
int a2d<T>::columns(){return nCols;}

template <class T>
T & a2d<T>::operator()(int i, int j){
  if(i >= nRows || i < 0 || j >= nCols || j < 0){
    cout << "Out of bounds indices ("<< i <<", "<<j<<
      ").  Max allowed ("<< nRows-1<<", "<<nCols-1<<").\n";
  }
  return v[i*nCols+j];
}

template <class T>
T * a2d<T>::operator()(int i){
  if(i >= nRows || i < 0){
    cout << "Out of bounds indices ("<< i <<", "<< " * "<<
      ").  Max allowed ("<< nRows-1<<", "<<nCols-1<<").\n";
  }
  return &v[i*nCols];
}

template <class T>
ostream & operator<< (ostream & o, a2d<T> a){
  for(int i=0; i<a.rows(); i++){
    for(int j=0; j<a.columns(); j++)
      o << a(i,j) << " ";
    o << endl;
  }
  return o;
}

template <class T>
istream & operator>> (istream & is, a2d<T> a){
  for(int i=0; i<a.rows(); i++){
    for(int j=0; j<a.columns(); j++)
      is >> a(i,j);
  }
  return is;
}

#endif
