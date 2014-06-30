#include <simplecpp>
const int pixelsize = 20, xinit = 30, yinit = 20, length = 10;

struct Snake{
  Circle *body;
  int headindex;
  char dir;
  Snake(){
    headindex = 0;
    body = new Circle[length];
    for(int i=0; i<length; i++)
      body[i].reset((xinit+i)*pixelsize+pixelsize/2,
		    yinit*pixelsize+pixelsize/2,  pixelsize/2);
    dir = 'w';
  }
  void move(){
    move(dir);
  }
  void move(char command){
    double xhead = body[headindex].getOrigin().getX();
    double yhead = body[headindex].getOrigin().getY();
    headindex = (headindex +length - 1) % length;
    if(command == 'w')
      body[headindex].reset(xhead-pixelsize, yhead, pixelsize/2);
    else if (command == 'n')
      body[headindex].reset(xhead, yhead-pixelsize, pixelsize/2);
    else if (command == 'e')
      body[headindex].reset(xhead+pixelsize, yhead, pixelsize/2);
    else if (command == 's')
      body[headindex].reset(xhead, yhead+pixelsize, pixelsize/2);
    else
      command = dir;
    dir = command;
  }
};

int main(){
  initCanvas("Snake", pixelsize*40, pixelsize*40);
  Snake s;
  wait(1);
  while(true){
    XEvent event;
    if(checkEvent(event)){  // returns false if no event has happened.
      if(keyPressEvent(event)){
	char c = charFromEvent(event);
	s.move(c);
      }
    }
    else s.move();
    wait(0.2);
  }
}
