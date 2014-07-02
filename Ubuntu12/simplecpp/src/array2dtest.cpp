#include <graphicsim.h>

void print(array2d<float> a){
    for(int i=0; i<a.rows(); i++){
    for(int j=0; j<a.columns(); j++)
      cout << a(i,j) << " ";
    cout << endl;
  }
}

main(){
  array2d<float> a(3,5);
  for(int i=0; i<3; i++)
    for(int j=0; j<5; j++)
      a(i,j) = 10*(i+1)+j;
  

  print(a);

  a(0,0) = 99;

  a(0,1) += 1;
  a(0,2)--;

  for(int i=0; i<3; i++){
    for(int j=0; j<5; j++)
      cout << a(i,j) << " ";
    cout << endl;
  }

  a(3,0) = 27;
}
    
