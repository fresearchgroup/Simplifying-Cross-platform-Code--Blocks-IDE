#include <simplecpp>

main(){
  initCanvas("Eigenvector demonstration", 1000, 0, 1000, 1000);
  Turtle t1,t2;

  t1.penDown(false);
  t2.penDown(false);

  t1.move(250, 250);
  t2.move(-250, 250);
  

  t1.penDown();
  t2.penDown();

  cout << "Give matrix entries 00 01 10 11: ";

  double A[2][2];

  cin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1];

  for(int i=0; i<36; i++){
    double angle = PI*i/18;
    double x = cos(angle);
    double y = sin(angle);

    double xt = A[0][0]*x + A[0][1]*y;
    double yt = A[1][0]*x + A[1][1]*y;

    t1.move(x*100, y*100);
    t2.move(xt*100, yt*100);

    t1.move(-x*100, -y*100);
    t2.move(-xt*100, -yt*100);
  }

  Turtle t3;
  //  t3.penDown(false);
  //  t3.move(250, -250);
  //  t3.penDown();

  double x=1, y=1;

  for(int i=0; i<10; i++){
    t3.move(100*x, 100*y);
    t3.move(-100*x, -100*y);

    double nx = A[0][0]*x + A[0][1]*y;
    double ny = A[1][0]*x + A[1][1]*y;
    
    double magnitude = sqrt(nx*nx+ny*ny);

    x = nx/magnitude;
    y = ny/magnitude;
    wait(1);
  }

  wait(5);
}
