#ifndef PANELAPI_H
#define PANELAPI_H

#include "copper/Plugin/PluginApi.h"


class PanelAPI: public BaseAPI {

  Q_OBJECT

  public:
    PanelAPI(QWidget *parent = 0);
    virtual ~PanelAPI();

    virtual std::string name() const = 0; // name used for display purposes
  	virtual std::string typeName() const = 0; // internal type name
};


typedef PL_ObjectFactory<GUI_Panel> GUI_PanelFactory;

#endif // PANELAPI_H