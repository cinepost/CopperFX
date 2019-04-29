#ifndef SCENE_VIEW_PANEL_GL_WIDGET_H
#define SCENE_VIEW_PANEL_GL_WIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QtGui/QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions_3_2_Core>

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram);
QT_FORWARD_DECLARE_CLASS(QOpenGLTexture);

#include "copper/Prims/Point.h"
#include "QGLViewportCamera.h"

namespace copper { namespace ui {

class SceneViewPanelGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
	Q_OBJECT

	public:
    explicit SceneViewPanelGLWidget(QWidget *parent = nullptr);
    ~SceneViewPanelGLWidget();

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void setClearColor(const QColor &color);

	signals:
    void clicked();

	protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent * /* event */) override;

  private:
  	void makeTestObject();

    QGLViewportCamera *active_camera;

  	QColor clearColor;
    QPoint lastPos;
    QOpenGLTexture *textures[6];
    QOpenGLShaderProgram *program;
    QOpenGLBuffer vbo;

    QMatrix4x4 m_model, m_view, m_projection;
};

}}

#endif // SCENE_VIEW_PANEL_GL_WIDGET_H