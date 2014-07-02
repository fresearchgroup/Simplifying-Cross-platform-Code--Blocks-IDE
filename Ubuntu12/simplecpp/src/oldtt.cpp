#include <graphicsim.h>
#include <cmath>

int main(int argc, char* argv[]){

  initCanvas("Program");
  cout << "start\n";

  Turtle t1,t2;

  for(int i=0; i<4;i++){
    t1.forward(100);
    t1.left(90);
  }
  
  t2.forward(100);


  usleep(10000000);

  closeCanvas();
  return 0;
}
