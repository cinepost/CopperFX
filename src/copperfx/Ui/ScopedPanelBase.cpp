#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "copperfx/Ui/ScopedPanelBase.h"


namespace copper { namespace ui {

ScopedPanelBase::ScopedPanelBase(QWidget *parent) : PanelBase(parent) {

}

}}