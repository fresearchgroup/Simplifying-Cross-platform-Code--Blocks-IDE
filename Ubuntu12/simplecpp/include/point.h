#ifndef _POINT_INCLUDED_
#define _POINT_INCLUDED_

#include <sprite.h>
#include <vector>

class Point : public Sprite{
 private:
  float radius;
  Position center;
  Point(const Point&);
  Point operator=(const Point&);
 public:
  Point();
  Point(const float radius, const Position center, Position point_origin=Position(0, 0));
  ~Point();

  void paint();
  RectBox boundingBox();
  float getXRadius();
  float getYRadius();
  Position getCenter();
  virtual void init(float radius, Position center, Position origin);
};

#endif
