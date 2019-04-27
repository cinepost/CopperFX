#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "wykobi/wykobi_matrix.hpp"

#include "copper/Prims/Vector.h"
#include "copper/Prims/Point.h"
#include "copper/Prims/Matrix.h"

namespace copper {

enum class Projection {
  PERSPECTIVE,
  ORTHOGONAL,
  SPHERICAL
};

class Camera {
  public:
    Camera(Point3d position = Point3d(0,0,0), Point3d target = Point3d(1,0,0), double fov_degrees = 41.0, double near_plane = 0.1, double far_plane = 1000.0);
    ~Camera(){};

    Matrix4d getTransform();

    void setProjectionType(Projection projection);

  protected:
    void buildUpVector(const Vector3d ground_normal=Vector3d(0,1,0));

  protected:
    Projection _projection;
    Point3d _position, _target;
    Vector3d _up, _ground;
    double _fov_degrees, _near_plane, _far_plane;

};

}

#endif // CAMERA_H