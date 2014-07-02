#include <simplecpp>

int main(){
  initCanvas("Text test",0,0,800,800);
  char *text = "Hi!";
  Rectangle r(100,100,textWidth(text),textHeight());
  r.setFill();

  Text t(100,100, text);

  r.imprint();
  t.imprint();
  getClick();

  for(int i=0; i<5; i++){
    t.move(10,10,false);
    r.move(10,10);
    wait(0.1);
  }
  getClick();

  t.setMessageColor(COLOR("red"));
  r.setColor(COLOR("blue"));

  for(int i=0; i<10; i++){
    t.move(10,-10,false);
    r.move(10,-10);
    wait(0.1);
  }
  getClick();
}


    
