#ifndef PANEL_MANAGER_H
#define PANEL_MANAGER_H

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <QFrame>
#include <QTabWidget>

#include "copperfx/Ui/PanelBase.h"


namespace copper { namespace ui {

typedef ObjectFactory<PanelBase> UiPanelFactory;

class PanelManager : public QTabWidget {
  Q_OBJECT

	public:
    PanelManager();
    PanelManager(QWidget *parent);
    virtual ~PanelManager();

    void addPanelByTypeName(std::string panel_type_name);

	private:
    static UiPanelFactory _panel_factory;

    friend class Application;

};

}}

#endif // PANEL_MANAGER_H