#include<simplecpp>

main_program{
  int clickPos;

  initCanvas();

  clickPos = getClick();

  cout << "Click position: ("<< clickPos/65536 <<", "
       << clickPos % 65536 <<")\n";
}
