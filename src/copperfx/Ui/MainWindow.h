#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "copperfx/Ui/Workspace.h"

class QAction;
class QMenu;
class QPlainTextEdit;
class QSessionManager;


namespace copper { namespace ui {

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        virtual ~MainWindow();

        Workspace *workspace();

        void loadFile(const QString &fileName);

    protected:
        void closeEvent(QCloseEvent *event) override;

    private slots:
        void newFile();
        void open();
        bool save();
        bool saveAs();
        void about();
        void documentWasModified();
    #ifndef QT_NO_SESSIONMANAGER
        void commitData(QSessionManager &);
    #endif

    private:
        void createActions();
        void createStatusBar();
        void readSettings();
        void writeSettings();
        bool maybeSave();
        bool saveFile(const QString &fileName);
        void setCurrentFile(const QString &fileName);
        QString strippedName(const QString &fullFileName);

        QPlainTextEdit *textEdit;
        QString curFile;

        Workspace *_workspace;
};

}}

#endif // MAIN_WINDOW_H