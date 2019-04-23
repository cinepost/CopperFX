#ifndef LOG_WINDOW_H
#define LOG_WINDOW_H

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

namespace copper { namespace ui {

class LogWindow : public QPlainTextEdit {
  Q_OBJECT
  
  public:
    void appendMessage(const QString& text);

  private:
    QFile m_logFile;
};


namespace log = boost::log;
namespace sinks = boost::log::sinks;

class LogSink : public sinks::basic_formatted_sink_backend<char, sinks::concurrent_feeding> {
  public:
    LogSink(LogWindow *logwnd)
        : _logwnd(logwnd){}

    void consume(const log::record_view& rec, const string_type& fstring);

  private:
    LogWindow *_logwnd;
};

}}

#endif // LOG_WINDOW_H