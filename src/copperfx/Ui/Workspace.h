#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <vector>

#include <QWidget>
#include <QFrame>
#include <QSplitter>
#include <QHBoxLayout>

#include "copperfx/Ui/PanelManager.h"


namespace copper { namespace ui {

class Workspace : public QWidget {
  Q_OBJECT

  public:
    Workspace(QWidget *parent = 0);
    virtual ~Workspace();

    std::vector<PanelManager*> panelManagers();

  private:
  	std::vector<PanelManager*> _panel_managers;

};

}}

#endif // WORKSPACE_H