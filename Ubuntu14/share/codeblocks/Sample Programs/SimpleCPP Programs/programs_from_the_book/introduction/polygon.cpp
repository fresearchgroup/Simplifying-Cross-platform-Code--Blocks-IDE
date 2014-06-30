#include <simplecpp>
main_program{
  int nsides;
  cout << "Type in the number of sides: ";
  cin >> nsides;

  turtleSim();

  repeat(nsides){
        forward(50);
        left(360.0/nsides);
  }
  wait(5);
  closeTurtleSim();
}
