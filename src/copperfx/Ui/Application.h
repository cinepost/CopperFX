#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>


namespace copper { namespace ui {

class Application final : public QApplication {
	public:
    Application(int& argc, char** argv);
    
};

}}

#endif // APPLICATION_H