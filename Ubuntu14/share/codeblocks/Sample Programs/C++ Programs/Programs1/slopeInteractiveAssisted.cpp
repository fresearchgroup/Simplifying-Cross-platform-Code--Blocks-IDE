#include <iostream>
using namespace std;

main () {

int x1, x2, y1, y2;

int slope;

  cout << "Input x1?";
  cin >> x1;

  cout << "Input y1?";
  cin >> y1;

  cout << "Input x2?";
  cin >> x2;

  cout << "Input y2?";
  cin >> y2;

  slope = (y2 - y1) / (x2 - x1);

  cout << "the slope is:" << slope << "\n";

}


