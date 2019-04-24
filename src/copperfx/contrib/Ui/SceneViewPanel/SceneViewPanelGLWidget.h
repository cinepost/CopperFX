#ifndef SCENE_VIEW_PANEL_GL_WIDGET_H
#define SCENE_VIEW_PANEL_GL_WIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QMouseEvent>
#include <QOpenGLBuffer>


QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram);
QT_FORWARD_DECLARE_CLASS(QOpenGLTexture);

namespace copper { namespace ui {

class SceneViewPanelGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
	Q_OBJECT

	public:
    explicit SceneViewPanelGLWidget(QWidget *parent = 0);
    ~SceneViewPanelGLWidget();

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void rotateBy(int xAngle, int yAngle, int zAngle);
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
  	void makeObject();

  	QColor clearColor;
    QPoint lastPos;
    int xRot;
    int yRot;
    int zRot;
    QOpenGLTexture *textures[6];
    QOpenGLShaderProgram *program;
    QOpenGLBuffer vbo;
};

}}

#endif // SCENE_VIEW_PANEL_GL_WIDGET_H