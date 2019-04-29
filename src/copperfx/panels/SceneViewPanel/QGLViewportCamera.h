#ifndef QGL_VIEWPORT_CAMERA
#define QGL_VIEWPORT_CAMERA

#include <QtGui/QVector3D>

#include "ViewportCamera.h"


namespace copper { namespace ui {

class QGLViewportCamera: public ViewportCamera {
	public:
		QVector3D position();
		QVector3D target();
		QVector3D up();
};

}}

#endif // QGL_VIEWPORT_CAMERA