#include <simplecpp>

main_program{
  int count;
  cout << "How many numbers: ";
  cin >> count;

  float num,sum=0;
  repeat(count){
    cout << "Give the next number: ";
    cin >> num;
    sum = sum + num;
  }

  cout << "Average is: ";
  cout << sum/count;
  cout << endl;
}
