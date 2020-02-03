#include <math.h> 

#include "Constants.h"
#include "Camera.h"

namespace copper {

Camera::Camera(Point3d position, Point3d target,Vector3d up, double fov_degrees, double near_plane, double far_plane):
	_position(position), _target(target), _up(up),
	_fov_degrees(fov_degrees), _near_plane(near_plane), _far_plane(far_plane) {
}

void Camera::setProjectionType(Projection projection){
	_projection = projection;
}

Projection Camera::projectionType() {
	return _projection;
}

void Camera::buildUpVector(Vector3d ground_normal) {
	Vector3d t2p = _position - _target;
  Vector3d left = -(t2p ^ _ground).normalized();
  _up = (t2p ^ left).normalized();
}

Matrix4d Camera::getTransform() {
	return Matrix4d::lookAt(_position, _target, _up);
}

Vector3d Camera::up(){
	return _up;
}

Point3d Camera::position(){
	return _position;
}

Point3d Camera::target(){
	return _target;
}

double Camera::nearPlane(){
	return _near_plane;
}

double Camera::farPlane(){
	return _far_plane;
}

double Camera::fovDegrees(){
	return _fov_degrees;
}

}