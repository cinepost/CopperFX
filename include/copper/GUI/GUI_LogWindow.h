#ifndef GUI_LOGWINDOW_H
#define GUI_LOGWINDOW_H

#include <boost/log/core.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/basic_sink_backend.hpp>
#include <boost/log/trivial.hpp>
#include <boost/shared_ptr.hpp>

#include <QFile>
#include <QWidget>
#include <QString>
#include <QScrollBar>
#include <QPlainTextEdit>

class GUI_LogWindow : public QPlainTextEdit {
  Q_OBJECT
  
  public:
    void appendMessage(const QString& text);

  private:
    QFile m_logFile;
};


namespace logging = boost::log;
namespace sinks = boost::log::sinks;

class GUI_LogSink : public sinks::basic_formatted_sink_backend<char, sinks::concurrent_feeding> {
  public:
    GUI_LogSink(GUI_LogWindow *logwnd)
        : _logwnd(logwnd){}

    void consume(const logging::record_view& rec, const string_type& fstring);

  private:
    GUI_LogWindow *_logwnd;
};


#endif // GUI_LOGWINDOW_H