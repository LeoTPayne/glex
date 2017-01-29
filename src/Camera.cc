#include "Camera.h"


Camera::Camera(){
	view_matrix = glm::mat4(
             glm::vec4(1.0, 0.0, 0.0, 0.0),
             glm::vec4(0.0, 1.0, 0.0, 0.0),
             glm::vec4(0.0, 0.0, 1.0, 0.0),
             glm::vec4(0.0, 0.0, 0.0, 1.0)
           );
}

Camera::~Camera(){
}

void Camera::move_x (float x){
	glm::mat4 m = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    	        glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(x, 0.0, 0.0, 1.0)
	);
	view_matrix = m * view_matrix;
}

void Camera::move_z (float z){
	glm::mat4 m = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(0.0, 0.0, z, 1.0)
	);
	view_matrix = m * view_matrix;
}


glm::mat4 Camera::getViewMatrix(){
	return view_matrix;
}

                   glm::vec4(0.0f, 0.0f, 3.0f, 0.0f), 
  		   glm::vec4(0.0f, 0.0f, 0.0f, 0.0f),
	   	   glm::vec4(0.0f, 0.0f, 0.0f, 0.0f), 
  		   glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
}

void Camera::Draw(GLuint) {
}
}
