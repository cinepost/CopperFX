#ifndef GUI_PANELMANAGER_H
#define GUI_PANELMANAGER_H

#include <QFrame>
#include <QTabWidget>

#include "copperfx/GUI/GUI_Panel.h"


namespace copper {

typedef ObjectFactory<GUI_Panel> GUI_PanelFactory;

class GUI_PanelManager : public QTabWidget {
  Q_OBJECT

	public:
    GUI_PanelManager(QWidget *parent, GUI_PanelFactory *panel_factory);
    virtual ~GUI_PanelManager();

    void addPanel(std::string panel_type_name);

	private:
    GUI_PanelFactory *_panel_factory;

};

}

#endif // GUI_PANELMANAGER_H