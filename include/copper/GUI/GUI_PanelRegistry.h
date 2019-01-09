#ifndef __GUI_PanelRegistry_h__
#define __GUI_PanelRegistry_h__

#include <string>
#include <map>

#include "UT/UT_Singleton.h"
#include "GUI_Panel.h"


typedef GUI_Panel *(*Panel_Constructor)();

class GUI_PanelRegistry: public UT_Singleton<GUI_PanelRegistry> {
	friend class UT_Singleton<GUI_PanelRegistry>;
	public:
		void	       addPanelType(std::string panel_type_name, Panel_Constructor constructor);
		GUI_Panel 	*getPanelByType(std::string ext);

	private:
		std::map<std::string, Panel_Constructor> panelsByType;
};


#endif // __GUI_PanelRegistry_h__