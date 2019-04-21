#ifndef GUI_PANELREGISTRY_H
#define GUI_PANELREGISTRY_H

#include <string>
#include <map>

#include "copper/Util/Singleton.h"
#include "copperfx/GUI/GUI_Panel.h"


namespace copper {

typedef GUI_Panel *(*Panel_Constructor)();

class GUI_PanelRegistry: public Singleton<GUI_PanelRegistry> {
	friend class Singleton<GUI_PanelRegistry>;
	public:
		void	       addPanelType(std::string panel_type_name, Panel_Constructor constructor);
		GUI_Panel 	*getPanelByType(std::string ext);

	private:
		std::map<std::string, Panel_Constructor> panelsByType;
};

}

#endif // GUI_PANELREGISTRY_H