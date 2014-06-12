#include <iostream>
using namespace std;
int fact (int i) {
  int result = 1;
  while (i > 0) {
    result = result * i;
    i = i-1;
  }
  cout << i;
  return(result);
}


int main () {
  int n;
  cout << "Enter a natural number: ";
  cin >> n;
  while (n < 0) {
    cout << "Please re-enter: ";
    cin >> n;
  }
  cout << n << "! = " << fact(n) << endl;
  return(0);
}
