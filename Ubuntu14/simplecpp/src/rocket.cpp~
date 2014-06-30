#include <graphicsim.h>
#include <cmath>

using namespace std;

// Rocket demo
// What is a rocket?
//
//
//	     /\
//	    /  \
//	   /    \
//	  /	 \
//	  +------+
//	  |      |
//	  |      |
//	  |      |
//	  |      |
//	  |      |
//	  |      |
//	  |      |
//	  |      |
//	  |      |
//	  |      |
//	  |      |
//	  +------+
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//



class Rocket{
public:
  Polygon nose;
  Polygon frame;
  Polygon left_fin;
  Polygon right_fin;
  Polygon red_flame;
  Polygon yellow_flame;

  Position origin;
  float orientation;
public:
  Rocket();

  void move(float xshift, float yshift);
  void rotate(float angle);
  void setOrientation(float new_orientation);
  Position getOrigin();
  float getOrientation();
};

Rocket::Rocket(){
  // Set members
  origin = Position(300, 300);
  orientation = 180;

  // Frame Co-ordinates
  float pts_frame[4][2] = {{-20, 0}, {-20, 80}, {20, 80}, {20, 0}};
  frame = Polygon(pts_frame, 4, origin, orientation);

  // Nose co-ordinates
  float pts_nose[3][2] = {{-20, 80}, {0, 100}, {20, 80}};
  nose = Polygon(pts_nose, 3, origin, orientation);

  // Left fin
  float pts_left_fin[3][2] = {{-20, 20}, {-30, -10}, {-20, 0}};
  left_fin = Polygon(pts_left_fin, 3, origin, orientation);

   // Right fin
  float pts_right_fin[3][2] = {{20, 20}, {30, -10}, {20, 0}};
  right_fin = Polygon(pts_right_fin, 3, origin, orientation);

   // Red flame
   float pts_red_flame[][2] = {{20, 0}, {0, -40}, {-20, 0}};
  red_flame = Polygon(pts_red_flame, 3, origin, orientation);
  red_flame.setFillColor(COLOR("red"));
  red_flame.setFill(true);

  // Yellow flame
  float pts_yellow_flame[][2] = {{15, 0}, {0, -15}, {-15, 0}};
  yellow_flame = Polygon(pts_yellow_flame, 3, origin, orientation);
  yellow_flame.setFillColor(COLOR("yellow"));
  yellow_flame.setFill(true); 
}

void Rocket::move(float xshift, float yshift){
  origin = Position(origin.GetXDistance() + xshift, origin.GetYDistance() + yshift);
  frame.move(xshift, yshift);
  nose.move(xshift, yshift);
  left_fin.move(xshift, yshift);
  right_fin.move(xshift, yshift);
  red_flame.move(xshift, yshift);
  yellow_flame.move(xshift, yshift);
}

void Rocket::rotate(float angle){
  angle = Sprite::toStandardAngle(angle);
  frame.rotate(angle);
  nose.rotate(angle);
  left_fin.rotate(angle);
  right_fin.rotate(angle);
  red_flame.rotate(angle);
  yellow_flame.rotate(angle);
  orientation = Sprite::toStandardAngle(orientation + angle);
}

void Rocket::setOrientation(float angle){
  angle = Sprite::toStandardAngle(angle);
  frame.setOrientation(angle);
  nose.setOrientation(angle);
  left_fin.setOrientation(angle);
  right_fin.setOrientation(angle);
  red_flame.setOrientation(angle);
  yellow_flame.setOrientation(angle);
  orientation = Sprite::toStandardAngle(angle);
}

Position Rocket::getOrigin(){
  return origin;
}

float Rocket::getOrientation(){
  return orientation;
}
int main(int argc, char* argv[]){
  initCanvas("Program");

  // Create rocket obj
  Rocket Apollo;

  XEvent event;
  // Event loop
  while(1){
    nextEvent(&event);

    if(event.type == MotionNotify){
      XPoint xp;
      xp.x = event.xmotion.x;
      xp.y = event.xmotion.y;
      drawCircle(xp, 2, COLOR("blue"));
    }

    if(event.type == ButtonPress){
      float ang = atan2(event.xbutton.y - Apollo.getOrigin().GetYDistance(), event.xbutton.x - Apollo.getOrigin().GetXDistance()) * 180 / 3.14;
      Apollo.setOrientation(ang - 90);      
    }
    if(event.type == KeyPress){
      if(event.xkey.keycode == KeyCode_ARROWLEFT)	
    	Apollo.rotate(-10);
      else if(event.xkey.keycode == KeyCode_ARROWRIGHT)
    	Apollo.rotate(10);
      else if(event.xkey.keycode == KeyCode_ARROWUP){
	// Move forward
	float theta = Apollo.getOrientation() * 3.145 / 180.0;
	Apollo.move(-5*sin(theta), 5*cos(theta));
	Apollo.red_flame.show();
	Apollo.yellow_flame.show();
	usleep(50000);
	Apollo.red_flame.hide();
	Apollo.yellow_flame.hide();
      }
      else if(event.xkey.keycode == KeyCode_ARROWDOWN){
	// Move backward
	float theta = Apollo.getOrientation() * 3.145 / 180.0;
	Apollo.move(5*sin(theta), -5*cos(theta));
	Apollo.red_flame.show();
	Apollo.yellow_flame.show();
	usleep(50000);
	Apollo.red_flame.hide();
	Apollo.yellow_flame.hide();	
      }
      else if(event.xkey.keycode == KeyCode_ESC)
	break;
    }
  }
  closeCanvas();
  return 0;
}
