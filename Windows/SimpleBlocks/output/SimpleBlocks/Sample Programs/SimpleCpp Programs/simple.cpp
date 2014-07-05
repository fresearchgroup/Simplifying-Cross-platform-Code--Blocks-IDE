#include <simplecpp>

main_program{
  turtleSim();
  repeat(6){
    repeat(20){
      forward(1);
      left(3);
    }
    repeat(120){
      forward(1);
      right(3);
    }
  }
}
