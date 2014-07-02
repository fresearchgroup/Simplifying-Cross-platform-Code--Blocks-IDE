#include <graphicsim.h>
#include <cmath>

using namespace std;

class Rocket : public Sprite{
public:
  Polygon *nose;
  Polygon *frame;
  Polygon *left_fin;
  Polygon *right_fin;
  Polygon *red_flame;
  Polygon *yellow_flame;

public:
  Rocket();
};

Rocket::Rocket(){
  // Set members
  origin = Position(300, 300);
  orientation = 180;

  cout << "before nose" << endl;

  // Frame Co-ordinates
  float pts_frame[4][2] = {{-20, 0}, {-20, 80}, {20, 80}, {20, 0}};

  cout << "after pts" << endl;


  frame = new Polygon(pts_frame, 4, origin, orientation);

  cout << "after poly" << endl;


  addPart(frame);
  // Nose co-ordinates
  float pts_nose[3][2] = {{-20, 80}, {0, 100}, {20, 80}};
  nose = new Polygon(pts_nose, 3, origin, orientation);
  addPart(nose);

  cout << "nose" << endl;

  // Left fin
  float pts_left_fin[3][2] = {{-20, 20}, {-30, -10}, {-20, 0}};
  left_fin = new Polygon(pts_left_fin, 3, origin, orientation);
  addPart(left_fin);

   // Right fin
  float pts_right_fin[3][2] = {{20, 20}, {30, -10}, {20, 0}};
  right_fin = new Polygon(pts_right_fin, 3, origin, orientation);
  addPart(right_fin);

   // Red flame
   float pts_red_flame[][2] = {{20, 0}, {0, -40}, {-20, 0}};
  red_flame = new Polygon(pts_red_flame, 3, origin, orientation);
  red_flame->setFillColor(COLOR("red"));
  red_flame->setFill(true);
  addPart(red_flame);

  // Yellow flame
  float pts_yellow_flame[][2] = {{15, 0}, {0, -15}, {-15, 0}};
  yellow_flame = new Polygon(pts_yellow_flame, 3, origin, orientation);
  yellow_flame->setFillColor(COLOR("yellow"));
  yellow_flame->setFill(true); 
  addPart(yellow_flame);
}


int main(int argc, char* argv[]){
  // Create rocket obj
  cout << ";;;" << endl;

  Rocket Apollo;

  XEvent event;
  // Event loop
  initCanvas("Program");

  cout << ";;;" << endl;

  while(1){
    nextEvent(&event);

    if(event.type == MotionNotify){
      XPoint xp;
      xp.x = event.xmotion.x;
      xp.y = event.xmotion.y;
      drawCircle(xp, 2, COLOR("blue"));
      cout << "circle." << endl;
    }

    if(event.type == ButtonPress){
      float ang = atan2(event.xbutton.y - Apollo.getOrigin().GetYDistance(), 
			event.xbutton.x - Apollo.getOrigin().GetXDistance()) * 180 / 3.14;
      Apollo.setOrientation(ang - 90);      
      cout << "Turning." << endl;
      float theta = Apollo.getOrientation() * 3.145 / 180.0;
	Apollo.move(-5*sin(theta), 5*cos(theta));
	Apollo.red_flame->show();
	Apollo.yellow_flame->show();
	usleep(50000);
	Apollo.red_flame->hide();
	Apollo.yellow_flame->hide();
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
	Apollo.red_flame->show();
	Apollo.yellow_flame->show();
	usleep(50000);
	Apollo.red_flame->hide();
	Apollo.yellow_flame->hide();
      }
      else if(event.xkey.keycode == KeyCode_ARROWDOWN){
	// Move backward
	float theta = Apollo.getOrientation() * 3.145 / 180.0;
	Apollo.move(5*sin(theta), -5*cos(theta));
	Apollo.red_flame->show();
	Apollo.yellow_flame->show();
	usleep(50000);
	Apollo.red_flame->hide();
	Apollo.yellow_flame->hide();	
      }
      else if(event.xkey.keycode == KeyCode_ESC)
	break;
    }
  }
  closeCanvas();
  return 0;
}
