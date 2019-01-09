#include <string>
#include <vector>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "GUI/GUI_PanelRegistry.h"

void GUI_PanelRegistry::addPanelType(std::string panel_type_name, Panel_Constructor constructor) {
	panelsByType.insert ( std::pair<std::string, Panel_Constructor>(panel_type_name, constructor) );
	BOOST_LOG_TRIVIAL(debug) << "Registered panel type \"" << panel_type_name << "\"";
}

GUI_Panel *GUI_PanelRegistry::getPanelByType(std::string panel_type_name) {
	return panelsByType[panel_type_name]();
}