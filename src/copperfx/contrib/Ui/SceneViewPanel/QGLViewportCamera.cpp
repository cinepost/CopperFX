#include "QGLViewportCamera.h"


namespace copper { namespace ui {

QVector3D QGLViewportCamera::position() {
	return QVector3D(_position.x, _position.y, _position.z);
}

QVector3D QGLViewportCamera::target() {
	return QVector3D(_target.x, _target.y, _target.z);
}

QVector3D QGLViewportCamera::up() {
	return QVector3D(_up.x ,_up.y ,_up.z);
}

}}