#include <simplecpp>

Point::Point():Sprite(){
  center = Position(0, 0);
  fill_color = COLOR("Black");
  fill = false;
  radius = 0.01;

  // paint yourself
  paint();
}

void Point::init(float in_radius, Position c, Position origin){
  fill_color = COLOR("Black");
  fill = false;
  center = c;
  setOrigin(origin);

  radius = (in_radius > 0) ? in_radius : 1;

  paint();
}

Point::Point(const float in_radius, const Position pt_center, Position point_origin):Sprite(point_origin, 0, 1, 1){
  init(in_radius, pt_center, point_origin);
}


Point::~Point(){
  // Do nothing
}

void Point::paint(){
   if(visible){
     float curr_x = center.GetXDistance();
     float curr_y = center.GetYDistance();

     XPoint res_center;
     res_center.x = int(curr_x * xscale * cos(orientation*PI/180.0) - 
		    curr_y * yscale * sin(orientation*PI/180.0) + 
			origin.GetXDistance());
     res_center.y = int(curr_x * xscale * sin(orientation*PI/180.0) + 
		    curr_y * yscale * cos(orientation*PI/180.0) + 
		    origin.GetYDistance());
    // Draw a circle
     drawEllipse(res_center, int(radius*2 * xscale), int(radius*2 * yscale),
		 fill_color, fill);  // need x and y diameter 
  }
}

RectBox Point::boundingBox(){
  Position res_center=getCenter();

  RectBox rect;
  rect.top_left = Position(res_center.GetXDistance() - radius * xscale, 
			   res_center.GetYDistance() - radius * yscale);
  rect.bottom_right = Position(res_center.GetXDistance() + radius * xscale, 
			       res_center.GetYDistance() + radius * yscale);

  return rect;
}

float Point::getXRadius(){
  return radius * xscale;
}

float Point::getYRadius(){
  return radius * yscale;
}

Position Point::getCenter(){
  float curr_x = center.GetXDistance();
  float curr_y = center.GetYDistance();

  return Position(curr_x * xscale * cos(orientation*PI/180.0) - 
		    curr_y * yscale * sin(orientation*PI/180.0) + 
		    origin.GetXDistance(),
		    curr_x * xscale * sin(orientation*PI/180.0) + 
		    curr_y * yscale * cos(orientation*PI/180.0) + 
		    origin.GetYDistance());
}
