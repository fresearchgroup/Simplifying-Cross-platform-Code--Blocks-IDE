#include <simplecpp>
#include <pose.h>
#include <polygon.h>

class House : public Composite{
public:
  Polygon* roof;
  Polygon* body;
  Polygon* window1;
  Polygon* window2;
  House(double dx, double dy, Composite* owner=NULL)
  : Composite(dx,dy,owner){
    float roofv[4][2]={-100,00, 0,100, 100,0, -100,0};
    roof = new Polygon(0,200,roofv,4,this);
    roof->setColor(COLOR("red"));
    float bodyv[5][2]={-100,00, -100,200, 100,200, 100,0, -100,0};
    body = new Polygon(0,0,bodyv,5,this);
    float windowv[5][2]={-20,-25, -20,25, 20,25, 20,-25, -20,-25};
    window1 = new Polygon(-25,75,windowv,5,this);
    window2 = new Polygon(25,75,windowv,5,this);
  }
};


int main(){
  initCanvas("Trtest",0,0,800,800);
  House h(200.0,300.0);
  h.rotate(PI);

  getClick();
  for(int i=0; i<5; i++){
    h.scale(0.9);
    wait(0.1);
  }
  getClick();
  for(int i=0; i<10; i++){
    h.rotate(0.1);
    wait(0.1);
  }
  getClick();

  for(int i=0; i<5; i++){
    h.move(10,10);
    wait(0.1);
  }

  getClick();
  for(int i=0; i<20; i++){
    h.window1->rotate(-PI/10,false);
    h.window2->rotate(PI/10);
    wait(0.1);
  }

  h.roof->setFill();

  getClick();
  for(int i=0; i<5; i++){
    h.move(-10,-10);
    wait(0.1);
  }
  getClick();
  for(int i=0; i<10; i++){
    h.rotate(-0.1);
    wait(0.1);
  }
  getClick();
  for(int i=0; i<5; i++){
    h.scale(1/0.9);
    wait(0.1);
  }
  getClick();

}
    
