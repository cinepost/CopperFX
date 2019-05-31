#ifndef __Renderer_OpenGL_h__
#define __Renderer_OpenGL_h__

#include <OpenGL/OpenGL.h>

#include "renderer.h"

class RendererOpenGL: public Renderer
{

    public:
        RendererOpenGL(void);
        ~RendererOpenGL(); 

        virtual int render(float time);

    private:
    	#ifdef __APPLE__
    		CGLContextObj ctx;
    	#elif __linux__

    	#endif
};

#endif // __Renderer_OpenGL_h__