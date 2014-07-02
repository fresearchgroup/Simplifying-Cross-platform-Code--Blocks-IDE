#include <simplecpp>
#include <rectangle.h>

main(){
  initCanvas("Rectangle test",0,0,1000,1000);
  Rectangle(475,475,900,900,false,COLOR("Blue")).imprint();
  wait(5);

  int disp = 100;
  for(int i=0; i<8; i++){
    for(int j=0; j<4; j++){
      Rectangle(disp + i*100, disp+ (2*j+(i%2))*100,100).imprint();
      Rectangle(disp + i*100, disp+ (2*j+((i+1)%2))*100,100,100,
		true, COLOR("Red")).imprint();
    }
  }
  wait(1);

  float x1=25, x2=925, y1=25, y2=925;
  float x=830,y=200,vx=3,vy=5,radius=10;

  Point ball(radius, Position(0,0), Position(x,y));
  ball.penDown(true);
  ball.setFill(true);
  ball.setFillColor(COLOR("Blue"));

  repeat(10){
    int temp;
    //    cin >> temp;
    float vwalltime, hwalltime, time;
    if(vx > 0) vwalltime = (x2-radius-x)/vx;
    else vwalltime = (x1+radius-x)/vx;

    if(vy > 0) hwalltime = (y2-radius-y)/vy;
    else hwalltime = (y1+radius-y)/vy;

    time = min(hwalltime,vwalltime);

    int steps = time+1;

    for(int i=0; i<steps; i++)
      ball.move(vx*time/steps,vy*time/steps);


    x +=vx*time;
    y +=vy*time;

    if(x == x1+radius || x == x2-radius) vx = -vx;
    if(y == y1+radius || y == y2-radius) vy = -vy;
    wait(0.5);
  }
  wait(5);

}
