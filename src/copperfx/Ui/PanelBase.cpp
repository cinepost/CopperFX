#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "copper/Plugin/ObjectFactory.h"
#include "copperfx/Ui/PanelBase.h"


namespace copper { namespace ui {

PanelBase::PanelBase() {
	_widget = nullptr;
}

}}