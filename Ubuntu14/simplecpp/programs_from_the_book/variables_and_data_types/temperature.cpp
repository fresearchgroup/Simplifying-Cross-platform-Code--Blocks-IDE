#include <simplecpp>

main_program{
  float centigrade, fahrenheit;

  cout << "Give temperature in Centigrade: ";
  cin >> centigrade;

  fahrenheit = 32 + centigrade * 9/5;
  cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
}
