#ifndef __GUI_SceneViewPanel_h__
#define __GUI_SceneViewPanel_h__

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "copperfx/GUI/GUI_Panel.h"
#include "copperfx/GUI/GUI_PanelRegistry.h"


namespace copper {

class GUI_SceneViewPanel : public GUI_Panel {

	Q_OBJECT

  public:
    GUI_SceneViewPanel(QWidget *parent = 0);
    ~GUI_SceneViewPanel();

  public:
    static GUI_Panel *panelConstructor(); // factory method

    virtual const std::string name() const;
    virtual const std::string typeName() const;
    virtual const unsigned int version() const;

};

void registerSceneViewPanelType(GUI_PanelRegistry *registry); // use registerPanelType(...) when writing plugin library

}

#endif // __GUI_SceneViewPanel_h__