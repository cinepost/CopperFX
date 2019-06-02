#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <OpenGL/CGLCurrent.h>

#include "renderer_opengl.h"

RendererOpenGL::RendererOpenGL() : Renderer() {
	#ifdef __APPLE__
	CGLPixelFormatAttribute attributes[4] = {
		kCGLPFAAccelerated,   // no software rendering
		kCGLPFAOpenGLProfile, // core profile with the version stated below
		(CGLPixelFormatAttribute) kCGLOGLPVersion_3_2_Core,
		(CGLPixelFormatAttribute) 0
	};

	CGLPixelFormatObj pix;
	CGLError errorCode;
	GLint num; // stores the number of possible pixel formats
	if ( CGLChoosePixelFormat( attributes, &pix, &num ) != kCGLNoError )  {
		fprintf( stderr, "Error choosing pixel format.\n" );
		exit( 1 );
	}

	if ( CGLCreateContext( pix, NULL, &ctx ) != kCGLNoError ) {
		fprintf( stderr, "Error creating CGL context\n" );
		exit( 1 );
	}

	CGLDestroyPixelFormat( pix );

	if ( CGLSetCurrentContext( ctx ) != kCGLNoError ) {
		fprintf( stderr, "Error setting CGL context current\n" );
		exit( 1 );
	}

	#elif __linux__

	#endif

	BOOST_LOG_TRIVIAL(debug) << "OpenGL rendering engine constructed!";
}

RendererOpenGL::~RendererOpenGL() {
	#ifdef __APPLE__
	CGLSetCurrentContext( NULL );
	CGLDestroyContext( ctx );
	#elif __linux__

	#endif
	BOOST_LOG_TRIVIAL(debug) << "OpenGL rendering engine destructed!";
}

int RendererOpenGL::render(float time) {
	display->open("/Users/max/Desktop/shout_test.exr", 800, 600);
	display->write();
	display->close();
	return 0;
}