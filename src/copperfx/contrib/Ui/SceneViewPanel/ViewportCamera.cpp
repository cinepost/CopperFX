#include "copper/Prims/Constants.h"
#include "copper/Prims/Matrix.h"

#include "ViewportCamera.h"


namespace copper { namespace ui {

void ViewportCamera::setViewportDimensions(double width_pixels, double height_pixels ) {
	_viewport_width_in_pixels = width_pixels;
	_viewport_height_in_pixels = height_pixels;
	if (width_pixels < height_pixels) {
	  _viewport_radius_in_pixels = 0.5 * width_pixels;
	} else {
		_viewport_radius_in_pixels = 0.5 * height_pixels;
	}
}

void ViewportCamera::pan(double delta_x_pixels, double delta_y_pixels ) {
	Vector3d direction = _target - _position;
  double distance_from_target = direction.length();
  direction.normalize();

  double translation_speed_in_units_per_radius = distance_from_target * tan( _fov_degrees / 2.0 / 180.0 * math::PI );
  double pixels_per_unit = _viewport_radius_in_pixels / translation_speed_in_units_per_radius;

  Vector3d right = direction ^ _up;

  Vector3d translation = right * (- delta_x_pixels / pixels_per_unit) + _up * (- delta_y_pixels / pixels_per_unit);

  _position = _position + translation;
  _target = _target + translation;
}

void ViewportCamera::orbit(double delta_x_pixels, double delta_y_pixels) {
	double pixelsPerDegree = 1000 / _orbiting_speed_degrees_per_radians;
	double radiansPerPixel = 1.0 / pixelsPerDegree * math::PI / 180.0;

	Vector3d t2p = _position - _target;
	Vector3d ground_normal(0,1,0);

	Matrix4d m = Matrix4d::rotationMatrix( - delta_x_pixels * radiansPerPixel, ground_normal );
	t2p = m * t2p;
	_up = m * _up;

	Vector3d right = (_up.normalized() ^ t2p.normalized()).normalized();
	m = Matrix4d::rotationMatrix( delta_y_pixels * radiansPerPixel, right );
	t2p = m * t2p;
	_up = m * _up;
	_position = _target + t2p;
}

void ViewportCamera::dolly( double delta_pixels, bool push_target_distance) {
	Vector3d direction = _target - _position;
	double distance_from_target = direction.length();
	direction.normalize();

	double translation_speed_in_units_per_radius = distance_from_target * tan( _fov_degrees / 2.0 / 180.0 * math::PI );
  double pixels_per_unit = _viewport_radius_in_pixels / translation_speed_in_units_per_radius;

	double dolly_distance = delta_pixels / pixels_per_unit;

	if (!push_target_distance){
    distance_from_target -= dolly_distance;
    if (distance_from_target < (_target_push_threshold * _near_plane)) {
        distance_from_target = _target_push_threshold * _near_plane;
    }
	}

	_position = _position + direction * dolly_distance;
	_target = _position + direction * distance_from_target;
}

void ViewportCamera::buildFrustum(double &left, double &right, double &bottom, double &top, double &near, double &far) {
  double tangent = tan( _fov_degrees / 2.0 / 180.0 * math::PI );
  double viewport_radius = _near_plane * tangent;
  double viewport_width, viewport_height;
  if (_viewport_width_in_pixels < _viewport_height_in_pixels) {
      viewport_width = 2.0 * viewport_radius;
      viewport_height = viewport_width * _viewport_height_in_pixels / _viewport_width_in_pixels;
  } else {
      viewport_height = 2.0 * viewport_radius;
      viewport_width = viewport_height * _viewport_width_in_pixels / _viewport_height_in_pixels;
  }

  left = - 0.5 * viewport_width; right =  0.5 * viewport_width,    // left, right
  bottom =  - 0.5 * viewport_height; top =  0.5 * viewport_height,   // bottom, top
  near = _near_plane; far = _far_plane;
 
}

}}