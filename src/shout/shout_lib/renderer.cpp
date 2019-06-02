#include "renderer.h"


Renderer::Renderer() {
	display = new Display("sdldisplay");
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
