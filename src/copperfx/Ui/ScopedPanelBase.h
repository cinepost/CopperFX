#ifndef SCOPED_PANEL_BASE_H
#define SCOPED_PANEL_BASE_H

#include <QWidget>

#include "copperfx/Ui/PanelBase.h"


namespace copper { namespace ui {

class ScopedPanelBase : public PanelBase {

  Q_OBJECT

  public:
    ScopedPanelBase(QWidget *parent = nullptr);
    virtual ~ScopedPanelBase() {};
};

}}

#endif // SCOPED_PANEL_BASE_H	