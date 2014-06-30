#include <simplecpp>

int main(){
  initCanvas("Trtest",0,0,800,800);
  Turtle c;

  for(int i=0; i<5; i++){
    c.forward(100);
    // c.rotate(2*PI/5);
    c.left(72);
  }

  for(int i=0; i<6; i++){
    c.forward(100);
    c.right(60);
  }

  c.imprint();
  getClick();
  for(int i=0; i<10; i++){
    c.forward(10);
    c.imprint();
    wait(0.1);
  }
  c.setColor(COLOR("blue"));
  getClick();
  for(int i=0; i<10; i++){
    c.scale(1.1);
    c.imprint();
    wait(0.1);
  }
  c.setColor(COLOR("red"));
  c.setFill();
  getClick();

  for(int i=0; i<10; i++){
    c.move(20,0);
    c.imprint();
    wait(0.1);
  }
  c.setColor(COLOR("green"));
  getClick();
}


    
