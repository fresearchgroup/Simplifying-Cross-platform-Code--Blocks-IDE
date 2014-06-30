#include <simplecpp>

Polygon::Polygon(Composite* owner)
  : Sprite(canvas_width()/2, canvas_height()/2, owner){
  init(NULL, 0);
}

Polygon::Polygon(const double x, const double y, const double points[][2], 
		 int no, Composite *owner)
  : Sprite(x,y,owner){
  init(points,no);
}

void Polygon::reset(const double x, const double y, 
		    const double points[][2], int no, Composite *owner){
  Sprite::reset(x,y,owner);
  init(points,no);
}

void Polygon::init(const double points[][2], int no_of_points){
  count = no_of_points;
  cout <<"Polygon init "<<count<<endl;
  for(int iter = 0; iter < count; iter ++){
    vertex.push_back(Position(points[iter][0], points[iter][1]));
  }
  show();
}

Polygon::~Polygon(){
  //if(vertex) delete []vertex;
}


void Polygon::paint(Pose *p){
  if(visible && vertex.size()>0 && count >0){
    XPoint xpt_vertex[count];
    if(p){
      Pose r = Pose(*p,pose);
      r.compute_res_vertex(xpt_vertex, vertex, count);
    }
    else pose.compute_res_vertex(xpt_vertex, vertex, count);
    drawPolygon(xpt_vertex, count, color, fill);
  }
}
