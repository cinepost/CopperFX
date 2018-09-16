#include "GUI/GUI_MainWindow.h"

GUI_MainWindow::GUI_MainWindow(){
     QWidget *widget = new QWidget;
     setCentralWidget(widget);

     QWidget *topFiller = new QWidget;
     topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

     infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to invoke a context menu</i>"));
     infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
     infoLabel->setAlignment(Qt::AlignCenter);

     QWidget *bottomFiller = new QWidget;
     bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

     QVBoxLayout *layout = new QVBoxLayout;
     layout->setMargin(5);
     layout->addWidget(topFiller);
     layout->addWidget(infoLabel);
     layout->addWidget(bottomFiller);
     widget->setLayout(layout);

     createActions();
     createMenus();

     QString message = tr("A context menu is available by right-clicking");
     statusBar()->showMessage(message);

     setWindowTitle(tr("Menus"));
     setMinimumSize(160, 160);
     resize(480, 320);
}

void GUI_MainWindow::createActions() {

     newAct = new QAction(tr("&New"), this);
     newAct->setShortcuts(QKeySequence::New);
     newAct->setStatusTip(tr("Create a new file"));
     connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

     alignmentGroup = new QActionGroup(this);
     alignmentGroup->addAction(leftAlignAct);
     alignmentGroup->addAction(rightAlignAct);
     alignmentGroup->addAction(justifyAct);
     alignmentGroup->addAction(centerAct);
     leftAlignAct->setChecked(true);
}

void GUI_MainWindow::createMenus() {
     fileMenu = menuBar()->addMenu(tr("&File"));
     fileMenu->addAction(newAct);
     fileMenu->addAction(openAct);
     fileMenu->addAction(saveAct);
     fileMenu->addAction(printAct);
     fileMenu->addSeparator();
     fileMenu->addAction(exitAct);

     editMenu = menuBar()->addMenu(tr("&Edit"));
     editMenu->addAction(undoAct);
     editMenu->addAction(redoAct);
     editMenu->addSeparator();
     editMenu->addAction(cutAct);
     editMenu->addAction(copyAct);
     editMenu->addAction(pasteAct);
     editMenu->addSeparator();

     helpMenu = menuBar()->addMenu(tr("&Help"));
     helpMenu->addAction(aboutAct);
     helpMenu->addAction(aboutQtAct);

     formatMenu = editMenu->addMenu(tr("&Format"));
     formatMenu->addAction(boldAct);
     formatMenu->addAction(italicAct);
     formatMenu->addSeparator()->setText(tr("Alignment"));
     formatMenu->addAction(leftAlignAct);
     formatMenu->addAction(rightAlignAct);
     formatMenu->addAction(justifyAct);
     formatMenu->addAction(centerAct);
     formatMenu->addSeparator();
     formatMenu->addAction(setLineSpacingAct);
     formatMenu->addAction(setParagraphSpacingAct);
}

void GUI_MainWindow::contextMenuEvent(QContextMenuEvent *event) {
     QMenu menu(this);
     menu.addAction(cutAct);
     menu.addAction(copyAct);
     menu.addAction(pasteAct);
     menu.exec(event->globalPos());
 }