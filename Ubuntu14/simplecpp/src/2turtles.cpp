#include <graphicsim.h>

class planet : public Turtle{
protected:
  float mass;
  float vx, vy;
  float ax, ay;  // previous acceleration values.
public:
  planet(){};
  
  planet(float m, Position p, float v1=0, float v2=0)
    : Turtle(p)
  {
    cout << "Created at " << origin.getX() << "," << origin.getY() << endl;
    mass = m;
    vx = v1;
    vy = v2;
    show();
  }
  void Estep(float dT, float fx, float fy){
    float dx = vx*dT;
    float dy = vy*dT;

    float ax = fx/mass; 
    float ay = fy/mass; 

    vx = vx + ax*dT;
    vy = vy + ay*dT;

    move(dx,dy);
    imprint();
    //    if(mass == 1)
    //      cout << origin.getX() << "," << origin.getY() << "   Force "
    //           << fx << "," << fy << "   " << dx << "," << dy << endl;

    float theta = atan2(vy,vx)*180/PI;
    setOrientation(theta);

  }

  void Frstep(float dT, float fx, float fy){
    ax = fx/mass; 
    ay = fy/mass; 

    float dx = vx*dT + ax*dT*dT/2;
    float dy = vy*dT + ay*dT*dT/2;

    move(dx,dy);
    imprint();
  }

  void Fmainstep(float dT, float fx, float fy){

    float nax = fx/mass;
    float nay = fy/mass;

    vx = vx + (ax+nax)*dT/2;
    vy = vy + (ay+nay)*dT/2;

    float theta = atan2(vy,vx)*180/PI;
    setOrientation(theta);

    //    if(mass == 1)
    //      cout << origin.getX() << "," << origin.getY() << "   Force "
    //           << fx << "," << fy << "   " << dx << "," << dy << endl;

    Frstep(dT, fx, fy);

  }

  float getMass(){
    return mass;
  }
};
      

int main(int argc, char* argv[]){

  initCanvas("Planet satellite system",300,0,800,800);
  setFrameTime(0);

  planet p1(400,Position(400,400),0,0), p2(1,Position(600,400),0,1.6);
  p1.penDown(false);
  //  p2.penDown(false);

  cout << "Set up the planets.\n";
  float dT=20;

  float x1,x2,y1,y2,f,fx,fy,theta; 

  float G=1.0;  // Gravitational constant!!

  for(int t=0;t<3000;++t){
    Position r1 = p1.getOrigin();
    Position r2 = p2.getOrigin();

    x1 = r1.GetXDistance();  y1 = r1.GetYDistance();
    x2 = r2.GetXDistance();  y2 = r2.GetYDistance();

    float dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    theta = atan2(y2-y1,x2-x1);

    //cout << theta*180/PI << "," << dist << ")";

    f = G*p1.getMass()*p2.getMass()/(dist*dist);

    fx = f*cos(theta);
    fy = f*sin(theta);

    if(t == 0){ p1.Frstep(dT, fx, fy);  p2.Frstep(dT, -fx, -fy);}
    else{
      p1.Fmainstep(dT,fx,fy); p2.Fmainstep(dT,-fx,-fy);
    }

  }

  usleep(10000000);

  closeCanvas();
  return 0;
}
