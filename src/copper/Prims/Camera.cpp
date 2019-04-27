#include <math.h> 

#include "Constants.h"
#include "Camera.h"

namespace copper {

Camera::Camera(Point3d position, Point3d target, double fov_degrees, double near_plane, double far_plane):
	_position(position), _target(target), 
	_fov_degrees(fov_degrees), _near_plane(near_plane), _far_plane(far_plane) {
	buildUpVector();
}

void Camera::setProjectionType(Projection projection){
	_projection = projection;
}

void Camera::buildUpVector(Vector3d ground_normal) {
	Vector3d t2p = _position - _target;
  Vector3d left = -(t2p ^ _ground).normalized();
  _up = (t2p ^ left).normalized();
}

Matrix4d Camera::getTransform() {
	return Matrix4d::lookAt(_position, _target, _up);
};

}