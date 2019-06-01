#ifndef __Display_h__
#define __Display_h__

#include <string>
#include <vector>

#include "prman/ndspy.h"

class Display {
	public:
		Display(const std::string& drivername);
		~Display();

  public:
    void open();
    void close();
    void write();

  private:
    void makeStringsParameter(const char* name, const char** strings, int count, UserParameter& parameter);

	private:
    PtDspyOpenFuncPtr               m_OpenFunc;
    PtDspyWriteFuncPtr              m_WriteFunc;
    PtDspyDeepWriteFuncPtr          m_DeepWriteFunc;
    PtDspyActiveRegionFuncPtr       m_ActiveRedionFunc;
    PtDspyCloseFuncPtr              m_CloseFunc;
    PtDspyFlushFuncPtr              m_FlushFunc;
    PtDspyReopenFuncPtr             m_ReopenFunc;
    PtDspyDelayCloseFuncPtr         m_DelayCloseFunc;
    PtDspyQueryFuncPtr              m_QueryFunc;

  private:
    std::string driver_name;

    PtDspyImageHandle image;
    PtFlagStuff flagstuff;                
};


#endif