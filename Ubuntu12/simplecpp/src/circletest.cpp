#include <simplecpp>

int main(){
  initCanvas("Trtest",0,0,800,800);
  Circle c(100,100, 30);
  c.imprint();
  getClick();
  for(int i=0; i<10; i++){
    c.move(10,10);
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
    c.move(10,10);
    c.imprint();
    wait(0.1);
  }
  c.setColor(COLOR("green"));
  getClick();
}


    
