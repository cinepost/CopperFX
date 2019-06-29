#ifndef SCENE_VIEW_PANEL_H
#define SCENE_VIEW_PANEL_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "copperfx/Ui/PanelBase.h"

#include "SceneViewPanelGLWidget.h"


namespace copper { namespace ui {

class SceneViewPanel : public PanelBase {
	Q_OBJECT

  public:
    SceneViewPanel();
    ~SceneViewPanel();

  public:
    const std::string& name() const override;

  private:
  	SceneViewPanelGLWidget *_gl_widget;

  public:
    // factory methods
    static std::string myTypeName();
    static PanelBase *myConstructor();

  private:
    static std::string _ui_name;

};

}}

#endif // SCENE_VIEW_PANEL_H