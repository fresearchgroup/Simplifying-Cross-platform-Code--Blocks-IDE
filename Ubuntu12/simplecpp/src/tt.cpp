#include <simplecpp>

int main(int argc, char* argv[]){

  //  turtlesim(10,10,1000,1000);
  turtlesim();
  setFrameTime(0);
  int n = 10;

  dotimes(5){
  dotimes(n){
    forward(100);
    left(360.0/n);
  }
  forward(20);
  }

  wait(5);

  closeCanvas();
  return 0;
}
