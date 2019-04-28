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
    Camera(Point3d position = Point3d(0,0,5), Point3d target = Point3d(0,0,0), Vector3d up = Vector3d(0,1,0), double fov_degrees = 41.0, double near_plane = 0.1, double far_plane = 1000.0);
    ~Camera(){};

    Matrix4d getTransform();
    Vector3d up();
    Point3d position();
    Point3d target();

    double fovDegrees();
    double nearPlane();
    double farPlane();

    void setProjectionType(Projection projection);
    Projection projectionType();

  protected:
    void buildUpVector(const Vector3d ground_normal=Vector3d(0,1,0));

  protected:
    Projection _projection;
    Point3d _position, _target;
    Vector3d _up, _ground;

    double _fov_degrees = 45.0;
    double _near_plane = 0.1;
    double _far_plane = 100;

};

}

#endif // CAMERA_H