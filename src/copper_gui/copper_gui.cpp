#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QMenuBar>

#include "GUI/GUI_MainWindow.h"
#include "Engine.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Engine& engine = Engine::Instance();

	GUI_MainWindow *window = new GUI_MainWindow();
    window->setWindowTitle(QString::fromUtf8("Copper FX"));
    window->resize(1200, 900);

    //QWidget *centralWidget = new QWidget(window);
	//QMenuBar *menu = new QMenuBar(centralWidget);

    //QMenu* menu1 = new QMenu("File");
	//menu1->addMenu(new QMenu("menu1_SubMenu"));	
	
	//QMenu* menu2 = new QMenu("Edit");
	//menu2->addMenu(new QMenu("menu2_SubMenu"));

	//menu->addMenu(menu1);
	//menu->addMenu(menu2);
	
	//window->setCentralWidget(centralWidget);


    window->show();
	return app.exec();
}