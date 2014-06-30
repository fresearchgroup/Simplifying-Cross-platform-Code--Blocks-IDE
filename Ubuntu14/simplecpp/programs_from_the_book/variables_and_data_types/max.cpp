#include <simplecpp>

main_program{
  int count;
  cout << "How many numbers: ";
  cin >> count;

  float num,maximum;

  cout << "Give the next number: ";
  cin >> maximum;

  repeat(count-1){                
    cout << "Give the next number: ";
    cin >> num;
    maximum = max(maximum,num);
  }
  cout << "Maximum is: " << maximum << endl;
}
