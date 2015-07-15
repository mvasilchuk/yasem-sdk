#ifndef ABSTRACTHTTPPROXYPRIVATE_H
#define ABSTRACTHTTPPROXYPRIVATE_H

#include <QString>

namespace yasem {
namespace SDK {

class HttpProxy;

class HttpProxyPrivate
{
public:
    explicit HttpProxyPrivate(HttpProxy* q) :
        q_ptr(q),
        m_host_name(""),
        m_port(0),
        m_max_rps(0)
    {
    }

    virtual ~HttpProxyPrivate() {}
protected:
    HttpProxy *q_ptr;
    QString m_host_name;
    quint16 m_port;
    quint16 m_max_rps;

    friend class HttpProxy;
};
}
}

#endif // ABSTRACTHTTPPROXYPRIVATE_H
