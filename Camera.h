#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp> 
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_


class Camera : public GameAsset {
public:
Camera();~Camera();
glm::mat4 getViewMatrix();

private:
std::unique_ptr<glm::mat4> view;

};




#endif // CAMERA_H
