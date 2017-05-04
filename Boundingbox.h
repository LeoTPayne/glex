#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <memory>
#include <utility>
#include <ostream>

using namespace std;

#include "Math.h"

enum AXIS {X, Y, Z};

class BoundingBox {
public:
  BoundingBox(const Vector3, const float, const float, const float);
  virtual ~BoundingBox();
  void SetCentre(Vector3 &);

  bool CollidesWith(const shared_ptr<BoundingBox>);

private:
  shared_ptr<Vector3> centre, extent_x, extent_y,extent_z;

  pair<float,float> projectOntoAxis(const BoundingBox &, enum AXIS);

  friend class SFAsset;
  friend ostream& operator<<(ostream &, const BoundingBox &);
};

#endif
