#include <iostream>
#include <cmath>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "SceneViewPanelGLWidget.h"


namespace copper { namespace ui {

SceneViewPanelGLWidget::SceneViewPanelGLWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      clearColor(Qt::black),
      program(0)
{
    active_camera = new QGLViewportCamera();
    memset(textures, 0, sizeof(textures));
    BOOST_LOG_TRIVIAL(debug) << "SceneViewPanelGLWidget constructed!";
}

SceneViewPanelGLWidget::~SceneViewPanelGLWidget() {
    delete active_camera;
    makeCurrent();
    vbo.destroy();
    for (int i = 0; i < 6; ++i)
        delete textures[i];
    delete program;
    doneCurrent();
    BOOST_LOG_TRIVIAL(debug) << "SceneViewPanelGLWidget constructed!";
}

QSize SceneViewPanelGLWidget::minimumSizeHint() const {
    return QSize(50, 50);
}

QSize SceneViewPanelGLWidget::sizeHint() const {
    return QSize(640, 360);
}

void SceneViewPanelGLWidget::setClearColor(const QColor &color) {
    clearColor = color;
    update();
}

void SceneViewPanelGLWidget::initializeGL() {
  std::cout << "1";
  QOpenGLFunctions::initializeOpenGLFunctions();
  std::cout << "2";
  makeTestObject();
  std::cout << "3";
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  #define PROGRAM_VERTEX_ATTRIBUTE 0
	#define PROGRAM_TEXCOORD_ATTRIBUTE 1

	QOpenGLShader *vshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    const char *vsrc =
        "attribute highp vec4 vertex;\n"
        "attribute mediump vec4 texCoord;\n"
        "varying mediump vec4 texc;\n"
        "uniform mediump mat4 matrix;\n"
        "void main(void)\n"
        "{\n"
        "    gl_Position = matrix * vertex;\n"
        "    texc = texCoord;\n"
        "}\n";
    vshader->compileSourceCode(vsrc);

    QOpenGLShader *fshader = new QOpenGLShader(QOpenGLShader::Fragment, this);
    const char *fsrc =
        "uniform sampler2D texture;\n"
        "varying mediump vec4 texc;\n"
        "void main(void)\n"
        "{\n"
        "    gl_FragColor = texture2D(texture, texc.st);\n"
        "}\n";
    fshader->compileSourceCode(fsrc);

    program = new QOpenGLShaderProgram;
    program->addShader(vshader);
    program->addShader(fshader);
    program->bindAttributeLocation("vertex", PROGRAM_VERTEX_ATTRIBUTE);
    program->bindAttributeLocation("texCoord", PROGRAM_TEXCOORD_ATTRIBUTE);
    program->link();

    program->bind();
    program->setUniformValue("texture", 0);

    m_view.setToIdentity();
    std::cout << "N";
    assert (glGetError() == GL_NO_ERROR);
}

void SceneViewPanelGLWidget::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
  m_model.setToIdentity();
  m_projection.setToIdentity();

  if ( active_camera->projectionType() == Projection::PERSPECTIVE) {
    m_projection.perspective(active_camera->fovDegrees(), (GLfloat)width / (GLfloat)height, active_camera->nearPlane(), active_camera->farPlane());
  } else {
    m_projection.ortho(-1.0, 1.0, -1.0, 1.0, active_camera->nearPlane(), active_camera->farPlane());
  }
  active_camera->setViewportDimensions(width, height);
  update();
}

void SceneViewPanelGLWidget::paintGL() {
  glClearColor(0.5, 0.5, 0.5, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  m_view.setToIdentity();
  m_view.lookAt(
    active_camera->position(), // Eye
    active_camera->target(), // Focal Point
    active_camera->up() // Up vector
  );

  QMatrix4x4 mvp = m_projection * m_view * m_model;
  //mvp.ortho(-0.5f, +0.5f, +0.5f, -0.5f, 4.0f, 15.0f);
  //mvp.translate(0.0f, 0.0f, -10.0f);
  //mvp.rotate(xRot / 16.0f, 1.0f, 0.0f, 0.0f);
  //mvp.rotate(yRot / 16.0f, 0.0f, 1.0f, 0.0f);
  //mvp.rotate(zRot / 16.0f, 0.0f, 0.0f, 1.0f);

  program->setUniformValue("matrix", mvp);
  program->enableAttributeArray(PROGRAM_VERTEX_ATTRIBUTE);
  program->enableAttributeArray(PROGRAM_TEXCOORD_ATTRIBUTE);
  program->setAttributeBuffer(PROGRAM_VERTEX_ATTRIBUTE, GL_FLOAT, 0, 3, 5 * sizeof(GLfloat));
  program->setAttributeBuffer(PROGRAM_TEXCOORD_ATTRIBUTE, GL_FLOAT, 3 * sizeof(GLfloat), 2, 5 * sizeof(GLfloat));

  for (int i = 0; i < 6; ++i) {
      textures[i]->bind();
      glDrawArrays(GL_TRIANGLE_FAN, i * 4, 4);
  }

  assert (glGetError() == GL_NO_ERROR);
}

void SceneViewPanelGLWidget::mousePressEvent(QMouseEvent *event) {
    lastPos = event->pos();
}

void SceneViewPanelGLWidget::mouseMoveEvent(QMouseEvent *event) {
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
      active_camera->orbit(-dx, dy);
    } else if (event->button() == Qt::MiddleButton) {
      active_camera->pan(-dx, dy); // camera panning
    } else if (event->buttons() & Qt::RightButton) {
      active_camera->dolly(3*(dy-dx), false);
    }
    lastPos = event->pos();
    update();
}

void SceneViewPanelGLWidget::mouseReleaseEvent(QMouseEvent * /* event */) {
    emit clicked();
}

void SceneViewPanelGLWidget::makeTestObject()
{
    static const int coords[6][4][3] = {
        { { +1, -1, -1 }, { -1, -1, -1 }, { -1, +1, -1 }, { +1, +1, -1 } },
        { { +1, +1, -1 }, { -1, +1, -1 }, { -1, +1, +1 }, { +1, +1, +1 } },
        { { +1, -1, +1 }, { +1, -1, -1 }, { +1, +1, -1 }, { +1, +1, +1 } },
        { { -1, -1, -1 }, { -1, -1, +1 }, { -1, +1, +1 }, { -1, +1, -1 } },
        { { +1, -1, +1 }, { -1, -1, +1 }, { -1, -1, -1 }, { +1, -1, -1 } },
        { { -1, -1, +1 }, { +1, -1, +1 }, { +1, +1, +1 }, { -1, +1, +1 } }
    };

    for (int j = 0; j < 6; ++j) {
      //textures[j] = new QOpenGLTexture(QImage(QString(":/images/side%1.png").arg(j + 1)).mirrored());
      textures[j] = new QOpenGLTexture(QImage(QString(":/textures/texture_2.png")).mirrored());
      textures[j]->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
      textures[j]->setMagnificationFilter(QOpenGLTexture::Linear);
    }

    QVector<GLfloat> vertData;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            // vertex position
            vertData.append(0.2 * coords[i][j][0]);
            vertData.append(0.2 * coords[i][j][1]);
            vertData.append(0.2 * coords[i][j][2]);
            // texture coordinate
            vertData.append(j == 0 || j == 3);
            vertData.append(j == 0 || j == 1);
        }
    }

    vbo.create();
    vbo.bind();
    vbo.allocate(vertData.constData(), vertData.count() * sizeof(GLfloat));
}

}}