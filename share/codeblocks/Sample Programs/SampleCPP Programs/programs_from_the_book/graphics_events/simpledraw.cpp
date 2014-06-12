#include <simplecpp>

int main(){
  initCanvas("Draw using the mouse", 800,500);
  const char escapekey = '\33';
  XEvent event;  
  short lastx=0, lasty=0;
  while(1){
    nextEvent(event);
    if(mouseButtonPressEvent(event)){
      lastx = event.xmotion.x; lasty = event.xmotion.y;
    }
    if(mouseDragEvent(event)){
      imprintLine(lastx, lasty, event.xbutton.x, event.xbutton.y);
      lastx = event.xbutton.x; lasty = event.xbutton.y;
    }
    if(keyPressEvent(event)){
      if(charFromEvent(event) == escapekey) break;
    }
  }
}
