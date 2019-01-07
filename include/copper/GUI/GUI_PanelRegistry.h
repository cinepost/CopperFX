#ifndef __GUI_PanelRegistry_h__
#define __GUI_PanelRegistry_h__

#include <string>
#include <map>

#include "GUI_Panel.h"

typedef GUI_Panel *(*Panel_Constructor)();

class GUI_PanelRegistry {
	public:
		static GUI_PanelRegistry& getInstance() {
			static GUI_PanelRegistry instance;  // Guaranteed to be destroyed.
																		    	// Instantiated on first use.
			return instance;
		}

	private:
		GUI_PanelRegistry() {} // Constructor? (the {} brackets) are needed here.

 		// C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
	public:
    GUI_PanelRegistry(GUI_PanelRegistry const&) = delete;
    void operator=(GUI_PanelRegistry const&) = delete;

    // Note: Scott Meyers mentions in his Effective Modern
    //       C++ book, that deleted functions should generally
    //       be public as it results in better error messages
    //       due to the compilers behavior to check accessibility
    //       before deleted status

	public:
		void	       addPanelType(std::string panel_type_name, Panel_Constructor constructor);
		GUI_Panel 	*getPanelByType(std::string ext);

	private:
		std::map<std::string, Panel_Constructor> panelsByType;
};


#endif // __GUI_PanelRegistry_h__