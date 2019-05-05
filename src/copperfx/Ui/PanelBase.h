#ifndef PANEL_BASE_H
#define PANEL_BASE_H

#include <QWidget>
#include <QBoxLayout>

#include "copper/Plugin/PluginApi.h"


namespace copper { namespace ui {

class PanelBase : public BaseAPI, public QWidget {
  //Q_OBJECT

  public:
    PanelBase(QWidget *parent = nullptr);
    virtual ~PanelBase();

  private:
  	//QBoxLayout *_layout;
};

}}

#endif // PANEL_BASE_H	