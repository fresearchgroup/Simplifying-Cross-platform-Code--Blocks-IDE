#ifndef _POSITION_INCLUDED_
#define _POSITION_INCLUDED_

class Position
{
  float xcor, ycor;
 public:
  Position(){
    xcor = ycor = 0.0;
  }

  Position(float x, float y){
    xcor = x;
    ycor = y;
  }

  float getX(){
    return xcor;
  }
  
  float getY(){
    return ycor;
  }
  float GetXDistance(){
    return xcor;
  }
  
  float GetYDistance(){
    return ycor;
  }
};
#endif
