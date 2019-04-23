#ifndef SCENE_VIEW_PANEL_H
#define SCENE_VIEW_PANEL_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QMouseEvent>
#include <QOpenGLBuffer>

#include "copperfx/Ui/PanelBase.h"


QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram);
QT_FORWARD_DECLARE_CLASS(QOpenGLTexture);

namespace copper { namespace ui {

class SceneViewPanel : public PanelBase {

  public:
    SceneViewPanel();
    ~SceneViewPanel();

    QWidget *widget() override;

  public:
    const std::string name() const override;
    const std::string typeName() const override;
    const unsigned int version() const override;

    // factory methods
    static std::string myTypeName();
    static PanelBase *myConstructor();

};

class SceneViewPanelWidget : public QOpenGLWidget, protected QOpenGLFunctions {
	Q_OBJECT

	public:
    explicit SceneViewPanelWidget(QWidget *parent = 0);
    ~SceneViewPanelWidget();

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

#endif // SCENE_VIEW_PANEL_H