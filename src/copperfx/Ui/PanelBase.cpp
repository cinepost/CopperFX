#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <QVBoxLayout>

#include "copperfx/Ui/PanelBase.h"


namespace copper { namespace ui {

PanelBase::PanelBase(QWidget *parent) : QWidget(parent) {
	//_layout = new QVBoxLayout(this);
}

PanelBase::~PanelBase() {
	//delete _layout;
}

}}