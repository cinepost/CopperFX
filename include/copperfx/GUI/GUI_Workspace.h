#ifndef GUI_WORKSPACE_H
#define GUI_WORKSPACE_H

#include <QWidget>


class GUI_Workspace : public QWidget
{
    Q_OBJECT

public:
    GUI_Workspace(QWidget *parent = 0);
    virtual ~GUI_Workspace();

};

#endif