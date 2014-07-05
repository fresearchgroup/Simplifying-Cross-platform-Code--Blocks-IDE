#ifndef _RECTANGLE_INCLUDED_
#define _RECTANGLE_INCLUDED_

#include <polygon.h>
#include <canvas.h>


class Rectangle: public Polygon{
 protected:
  double width, height;
 public:
  Rectangle(double cx, double cy, double w, double h=-1, Composite* owner=NULL);
  Rectangle(Composite* owner=NULL);
  virtual void init(double cx, double cy, double w, double h=-1, Composite* owner=NULL);
  virtual void reset(double cx, double cy, double w, double h=-1, Composite* owner=NULL);
  double getWidth();
  double getHeight();
    };

#endif
