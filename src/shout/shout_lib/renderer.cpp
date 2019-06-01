#include "renderer.h"


Renderer::Renderer() {
	display = new Display("houdini");
}


Renderer::~Renderer() {
	if (display)
		delete display;
}


float Renderer::getFPS() {
	//if (scene)
	//	return scene->getFPS();

	return fps;
}
