#ifndef VIEWPORT_CAMERA_H
#define VIEWPORT_CAMERA_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "wykobi/wykobi_matrix.hpp"

#include "copper/Prims/Vector.h"
#include "copper/Prims/Point.h"
#include "copper/Prims/Camera.h"

namespace copper { 

typedef wykobi::matrix<double, 4, 4> Matrix4x4d;

namespace ui {

class ViewportCamera: public Camera {
  public:
    void setViewportDimensions(double width_pixels, double height_pixels );

    void pan( double delta_x_pixels, double delta_y_pixels );
    void orbit( double delta_x_pixels, double delta_y_pixels );
    void dolly( double delta_pixels, bool push_target_distance = true );

    void buildFrustum( double &left, double &right, double &bottom, double &top, double &near, double &far );

  private:
    double _target_push_threshold = 0.1;
    double _orbiting_speed_degrees_per_radians = 300.0;
    double _viewport_width_in_pixels = 10;
    double _viewport_height_in_pixels = 10;
    double _viewport_radius_in_pixels = 5;
};

}}

#endif // VIEWPORT_CAMERA_H