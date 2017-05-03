#include "BoundingBox.h"

BoundingBox::BoundingBox(const Vector2 centre,
			     const int width,
			     const int height) :
  centre(make_shared<Vector2>(centre)),
  extent_x(make_shared<Vector2>(Vector2((float) width/2.0, 0))),
  extent_y(make_shared<Vector2>(Vector2(0, (float) height/2.0)))
  extent_z(make_shared<Vector2>(Vector2(0, (float) depth/2.0)))
 {
}

BoundingBox::~BoundingBox() {
  centre.reset();
  extent_x.reset();
  extent_y.reset();
  extent_z.reset();
}

void BoundingBox::SetCentre(Vector2 & v) {
  centre = make_shared<Vector2>(v);
}

bool straddles(const pair<float, float> & a, const pair<float, float> & b) {
  return (a.first >= b.first && a.first <= b.second)  // a1 intersects b
    || (a.second >= b.first && a.second <= b.second)  // a2 intersects b
    || (b.first >= a.first && b.first <= a.second)    // b1 intersects a
    || (b.second >= a.first && b.second <= a.second); // b2 intersects a
}

pair<float,float> BoundingBox::projectOntoAxis(const BoundingBox & b, enum AXIS axis) {
  float lo, hi, dp;

  switch (axis) {
  case X:
    {
      Vector2 bx = *b.extent_x;
      lo  = projection( Point2(Vector2(*(b.centre)) + (bx * -1)), xAxis());
      hi  = projection( Point2(Vector2(*(b.centre)) + bx), xAxis());
    }
    break;
  case Y:
    {
      Vector2 by = *b.extent_y;
      lo  = projection( Point2(Vector2(*(b.centre)) + (by * -1)), yAxis());
      hi  = projection( Point2(Vector2(*(b.centre)) + by), yAxis());
    }
    break;
  }
    case Z:
    {
      Vector2 by = *b.extent_z;
      lo  = projection( Point2(Vector2(*(b.centre)) + (by * -1)), zAxis());
      hi  = projection( Point2(Vector2(*(b.centre)) + by), zAxis());
    }
    break;
  }

  return make_pair(lo, hi);
}

bool BoundingBox::CollidesWith(const shared_ptr<BoundingBox> b) {
  pair<float, float> 
    a_x_proj = projectOntoAxis(*this, X),
    a_y_proj = projectOntoAxis(*this, Y),
    a_z_proj = projectOntoAxis(*this, Z),	
    b_x_proj = projectOntoAxis(*b, X),
    b_y_proj = projectOntoAxis(*b, Y),
    b_z_proj = projectOntoAxis(*b, Z);

  return (straddles(a_x_proj, b_x_proj)) && (straddles(a_y_proj, b_y_proj)) && (straddles(a_z_proj, b_z_proj));
}

ostream& operator<<(ostream& os, const BoundingBox& obj) {
  os << "c:(" << obj.centre->getX() << ", " << obj.centre->getY() << ") w:" << obj.centre->getZ() << ") d:" << (obj.extent_x->getX()*2) << " h:" << (obj.extent_y->getY()*2) << (obj.extent_->getZ()*2);
  return os;
}
