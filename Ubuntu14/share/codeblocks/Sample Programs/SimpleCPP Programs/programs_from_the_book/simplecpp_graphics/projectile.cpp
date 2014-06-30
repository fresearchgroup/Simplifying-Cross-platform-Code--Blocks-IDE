#include <simplecpp>

main_program{
  initCanvas("Projectile motion", 500,500);

  int start = getClick();

  Circle sp(start /65536, start % 65536, 5);
  sp.penDown();

  double vx=1,vy=-5;

  repeat(100){
    sp.move(vx,vy);
    vy += .1;
    wait(0.1);
  }

  getClick();
}
