#ifndef __GUI_Panel_h__
#define __GUI_Panel_h__

#include <QWidget>

#include "copper/PL/PL_ObjectFactory.h"
#include "copperfx/GUI/GUI_Panel.h"


class GUI_Panel : public QWidget {

  Q_OBJECT

  public:
    GUI_Panel(QWidget *parent = 0);
    virtual ~GUI_Panel();

    virtual const char  *panelTypeName() const = 0;
};


typedef PL_ObjectFactory<GUI_Panel> GUI_PanelsFactory;

#endif // __GUI_Panel_h__