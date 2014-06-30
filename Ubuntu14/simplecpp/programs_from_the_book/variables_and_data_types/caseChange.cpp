#include <simplecpp>

main_program{
  char small, capital;
  
  cout << "Type in any lower case letter: ";
  cin >> small;

  capital = small + 'A' - 'a';

  cout << capital << endl;
}
