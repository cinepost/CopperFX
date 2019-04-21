#ifndef GUI_PANEL_H
#define GUI_PANEL_H

#include <QWidget>

#include "copper/Plugin/PluginApi.h"
#include "copper/Plugin/ObjectFactory.h"

#include "copperfx/GUI/GUI_Panel.h"

namespace copper {

class GUI_Panel : public QWidget, public BaseAPI {

  Q_OBJECT

  public:
    GUI_Panel(QWidget *parent = 0);
    virtual ~GUI_Panel();

  	virtual const std::string typeName() const = 0; // internal type name;
};

}

#endif // GUI_PANEL_H	