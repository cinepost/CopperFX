#ifndef __GUI_Panel_h__
#define __GUI_Panel_h__

#include <QWidget>

#include <GUI/GUI_Panel.h>


class GUI_Panel : public QWidget {

  Q_OBJECT

  public:
    GUI_Panel(QWidget *parent = 0);
    virtual ~GUI_Panel();

    virtual const char  *panelTypeName() const = 0;
};

#endif // __GUI_Panel_h__