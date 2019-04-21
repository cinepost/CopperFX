#ifndef PL_PANELAPI_H
#define PL_PANELAPI_H

#include "copper/PL/PL_PluginApi.h"


class PL_PanelAPI: public PL_BaseAPI {

  Q_OBJECT

  public:
    PL_PanelAPI(QWidget *parent = 0);
    virtual ~PL_PanelAPI();

    virtual std::string name() const = 0; // name used for display purposes
  	virtual std::string typeName() const = 0; // internal type name
};


typedef PL_ObjectFactory<GUI_Panel> GUI_PanelFactory;

#endif // GUI_PANELAPI_H