#ifndef PANEL_BASE_H
#define PANEL_BASE_H

#include <QWidget>

#include "copper/Plugin/PluginApi.h"

#include "copperfx/Ui/PanelBase.h"

namespace copper { namespace ui {

class PanelBase : public BaseAPI, public QWidget {

  //Q_OBJECT

  public:
    PanelBase(QWidget *parent = nullptr);
    virtual ~PanelBase() {};
};

}}

#endif // PANEL_BASE_H	