#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "GUI/GUI_MainWindow.h"
#include "Engine.h"

int main(int argc, char *argv[])
{
	//Q_INIT_RESOURCE(application);

	Engine& engine = Engine::Instance();

	QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("RedSoft");
    QCoreApplication::setApplicationName("CopperFX");
    QCoreApplication::setApplicationVersion("0.0.001");

    // Retina display support for Mac OS, iOS and X11:
    // http://blog.qt.io/blog/2013/04/25/retina-display-support-for-mac-os-ios-and-x11/
    //
    // AA_UseHighDpiPixmaps attribute is off by default in Qt 5.1 but will most
    // likely be on by default in a future release of Qt.
    app.setAttribute(Qt::AA_UseHighDpiPixmaps);

    //QIcon appIcon;
    //appIcon.addFile(":/Icons/AppIcon32");
    //appIcon.addFile(":/Icons/AppIcon128");
    //app.setWindowIcon(appIcon);

    // Load stylesheet
    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        app.setStyleSheet(ts.readAll());
    }

    GUI_MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}