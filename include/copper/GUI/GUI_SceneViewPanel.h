#ifndef __GUI_SceneViewPanel_h__
#define __GUI_SceneViewPanel_h__

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include <GUI/GUI_Panel.h>
#include <GUI/GUI_PanelRegistry.h>


class GUI_SceneViewPanel : public GUI_Panel {

	Q_OBJECT

  public:
    GUI_SceneViewPanel(QWidget *parent = 0);
    ~GUI_SceneViewPanel();

  public:
    static GUI_Panel *panelConstructor(); // factory method

    virtual const char  *panelTypeName() const;

};

void registerSceneViewPanelType(GUI_PanelRegistry *registry); // use registerPanelType(...) when writing plugin library

#endif // __GUI_SceneViewPanel_h__