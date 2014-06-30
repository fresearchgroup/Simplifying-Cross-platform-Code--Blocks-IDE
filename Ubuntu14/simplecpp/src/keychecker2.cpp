#include <simplecpp>

int main(){

  initCanvas("Key Checker Program");

  Line(Position(100,100), Position(500,500));
  //  l.setLineColor(COLOR("yellow"));

  char *keyname; // Pointer to string
  
  string t1 = "Press key to get its code +";

  XEvent event;  // This is event structure

  // You can ignore XPoint
  XPoint p = {200, 100};   // XPoint is simple structure


  // Print messege on screen
  drawText(p, t1.c_str(), COLOR("blue"));

  Line(Position(p.x-textWidth(t1)/2,p.y+textHeight()/2),
       Position(p.x+textWidth(t1)/2,p.y+textHeight()/2)).imprint();
  Line l2(Position(p.x+textWidth(t1)/2,p.y-textHeight()/2),
	  Position(p.x+textWidth(t1)/2,p.y+textHeight()/2));

  p.y += 15+textHeight();
  drawText(p, "Click to exit", COLOR("blue"));

  wait(5);
}
