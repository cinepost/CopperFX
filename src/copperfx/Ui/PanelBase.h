#ifndef PANEL_BASE_H
#define PANEL_BASE_H

#include <QWidget>

#include "copper/Plugin/PluginApi.h"
#include "copper/Plugin/ObjectFactory.h"

#include "copperfx/Ui/PanelBase.h"

namespace copper { namespace ui {

class PanelBase : public BaseAPI { //,public QWidget {

  //Q_OBJECT

  public:
    PanelBase();
    virtual ~PanelBase() {};

    virtual QWidget *widget() = 0;

  	//virtual const std::string typeName() const = 0; // internal type name;
  protected:
  	QWidget *_widget;
};

}}

#endif // PANEL_BASE_H	