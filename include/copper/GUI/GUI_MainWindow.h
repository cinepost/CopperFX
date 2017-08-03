#ifndef __GUI_MainWindow_h__
#define __GUI_MainWindow_h__

class GUI_MainWindow : public QMainWindow
 {
     Q_OBJECT

 public:
     GUI_MainWindow();

 protected:
     void contextMenuEvent(QContextMenuEvent *event);


 private slots:
     void newFile();
     void open();
     void save();
     void print();
     void undo();
     void redo();
     void cut();
     void copy();
     void paste();
     void bold();
     void italic();
     void leftAlign();
     void rightAlign();
     void justify();
     void center();
     void setLineSpacing();
     void setParagraphSpacing();
     void about();
     void aboutQt();

 private:
     void createActions();
     void createMenus();


     QMenu *fileMenu;
     QMenu *editMenu;
     QMenu *formatMenu;
     QMenu *helpMenu;
     QActionGroup *alignmentGroup;
     QAction *newAct;
     QAction *openAct;
     QAction *saveAct;
     QAction *printAct;
     QAction *exitAct;
     QAction *undoAct;
     QAction *redoAct;
     QAction *cutAct;
     QAction *copyAct;
     QAction *pasteAct;
     QAction *boldAct;
     QAction *italicAct;
     QAction *leftAlignAct;
     QAction *rightAlignAct;
     QAction *justifyAct;
     QAction *centerAct;
     QAction *setLineSpacingAct;
     QAction *setParagraphSpacingAct;
     QAction *aboutAct;
     QAction *aboutQtAct;
     QLabel *infoLabel;
 };