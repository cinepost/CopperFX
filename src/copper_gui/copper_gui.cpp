#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "GUI/GUI_MainWindow.h"
#include "Engine.h"

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(application);

	QApplication app(argc, argv);
	QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationName("Application Example");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

	Engine& engine = Engine::Instance();

	GUI_MainWindow mainWin;
    mainWin.show();
    return app.exec();
}