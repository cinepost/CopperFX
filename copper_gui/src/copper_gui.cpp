#include <QApplication>
#include <QPushButton>

#include "copper/include/Engine.h"

int main(int argc, char **argv)
{
  Engine& engine = Engine::Instance();

  QApplication app (argc, argv);

  QPushButton button ("Hello world !");
  button.show();

 return app.exec();
}