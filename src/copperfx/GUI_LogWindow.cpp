#include "copperfx/GUI/GUI_LogWindow.h"

void GUI_LogWindow::appendMessage(const QString& text) {
    this->appendPlainText(text); // Adds the message to the widget
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->maximum()); // Scrolls to the bottom
    //m_logFile.write(text); // Logs to file
}

void GUI_LogSink::consume(const logging::record_view& rec, const string_type& fstring) {
	std::ostringstream os;
	os << "<" << rec[boost::log::trivial::severity] << "> " << fstring;
	//::PostMessage(hwnd_, UWM_LOG_MESSAGE, 0, (LPARAM)strdup(os.str().c_str()));
	_logwnd->appendMessage(os.str().c_str());
}