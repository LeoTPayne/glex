using namespace std;
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello

#include <memory>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Boundingbox.h"
#include "Boundingbox.cc"

 // This piece of code is testing the bounding boxs collision which is being forced to happen by making B1 and B2 collide
BOOST_AUTO_TEST_CASE(Boundingbox)
{
    auto b1 = make_shared<BoundingBox>(BoundingBox(Vector3(0.0f, 0.0f, 0.0f), 0.5f, 0.5f, 0.5f));
    auto b2 = make_shared<BoundingBox>(BoundingBox(Vector3(0.4f, 0.4f, 0.4f), 0.5f, 0.5f, 0.5f));
    BOOST_CHECK( b1->CollidesWith(b2) );
    BOOST_CHECK( b2->CollidesWith(b1) );
  
}

