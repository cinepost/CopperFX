#include <cstdio>    // fileno()
#include <unistd.h>  // isatty()
#include <csignal>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "copperfx/Ui/Application.h"
#include "copperfx/Ui/LogWindow.h"
#include "copperfx/Ui/MainWindow.h"
#include "copper/Engine.h"


namespace logging = boost::log;
namespace sinks = boost::log::sinks;

using namespace copper;

ui::LogWindow *logWindow = nullptr;

typedef sinks::synchronous_sink< ui::LogSink > sink_t;

void initGuiLog(ui::LogWindow *logwnd) {
  boost::shared_ptr< logging::core > core = logging::core::get();

  // Construct gui logging backend separately and pass it to the frontend
  boost::shared_ptr< ui::LogSink > backend(new ui::LogSink(logwnd));
  boost::shared_ptr< sink_t > gui_sink(new sink_t(backend));
  core->add_sink(gui_sink);

  // We can manage filtering through the sink interface
  //gui_sink->set_filter(expr::attr< severity_level >("Severity") >= warning);
}

void signalHandler( int signum ){
    BOOST_LOG_TRIVIAL(debug) << "Interrupt signal (" << signum << ") received !";

    // cleanup and close up stuff here
    if(logWindow)delete logWindow;  
    exit(signum); // terminate program
}

void myQtMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    }
}

int main(int argc, char *argv[])
{
    // Set up logging level quick 
    logging::core::get()->set_filter( logging::trivial::severity >= logging::trivial::debug );

    // Basic signal handlers
    signal(SIGTERM, signalHandler);
    signal(SIGABRT, signalHandler);

    // qt messages handler
    qInstallMessageHandler(myQtMessageHandler);

	ui::Application app(argc, argv);
    QCoreApplication::setOrganizationName("RedSoft");
    QCoreApplication::setApplicationName("CopperFX");
    QCoreApplication::setApplicationVersion("0.0.001");

    // Show simple QT logging window first so we can see debug messages while everything is
    // being initialized. Later we'll attach it to main window. This only applies then copper
    // started from Desktop ( or /Application on macos )
    
    if (! isatty(fileno(stdin))) {
        // We were launched from inside the desktop
        logWindow = new ui::LogWindow();
        logWindow->show();
        initGuiLog(logWindow);
    }

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
    QFile f(":/styles/dark");
    if (!f.exists()) {
        BOOST_LOG_TRIVIAL(warning) << "Unable to set stylesheet, file not found !";
    } else {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        app.setStyleSheet(ts.readAll());
    }

    // Now it's time to init engine core
    Engine::getInstance().init();

    ui::MainWindow mainWindow;
    mainWindow.show();
    //if(logWindow)mainWindow.workspace()->setCentralWidget( logWindow ); // attach log window
    
    return app.exec();
}