#ifndef TIMESHIFT_H
#define TIMESHIFT_H

#include "abstractpluginobject.h"

#include <QUrl>

namespace yasem {

namespace SDK {

class TimeShift: public AbstractPluginObject
{
    Q_OBJECT
public:
    enum TimeShiftError {
        NO_ERROR,
        URL_NOT_SPECIFIED,
        URL_NOT_FOUND,
        MEMORY_LIMIT_EXCEEDED,
        CANNOT_WRITE_CACHE,
        SOCKET_ERROR,

    };

    TimeShift(Plugin* plugin);
    virtual ~TimeShift();

    static bool isAvailable();
    static TimeShift* instance();

    virtual TimeShiftError start() = 0;
    virtual TimeShiftError stop() = 0;
    virtual void setInputURL(const QUrl& url);
    virtual QUrl getInputURL() const;
    virtual QUrl getOutputURL() const;
    virtual void clean() = 0;

protected:
    virtual void setOutputUrl(const QUrl& url);
    QUrl m_input_url;
    QUrl m_output_url;

signals:
    void error(const TimeShiftError error);
    void inputUrlChanged(const QUrl& url);
    void outputUrlChanged(const QUrl& url);
    void started();
    void stopped();
    void cleaned();
};

}
}

#endif // TIMESHIFT_H
