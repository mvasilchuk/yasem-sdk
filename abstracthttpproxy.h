#ifndef ABSTRACTHTTPPROXY_H
#define ABSTRACTHTTPPROXY_H

#include "abstractpluginobject.h"

namespace yasem {
namespace SDK {

class HttpProxyPrivate;

class HttpProxy: public AbstractPluginObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HttpProxy)
public:
    explicit HttpProxy(Plugin* plugin);
    virtual ~HttpProxy();

    virtual void setHostHame(const QString &host_name);
    virtual QString hostName();

    virtual void setPort(quint16 port);
    virtual quint16 port();

    virtual void setMaxRequestPerSecond(quint16 max_rps);
    virtual quint16 getMaxRequestPerSecond();

    virtual bool isRpsLimited();

public slots:
    virtual bool startServer() = 0;
    virtual bool stopServer() = 0;
    virtual bool isRunning() = 0;

protected:
    //WebServerPlugin(WebServerPluginPrivate &d): d_ptr(&d) {}
    // allow subclasses to initialize with their own concrete Private
    HttpProxyPrivate *d_ptr;
};

}

}

#endif // ABSTRACTHTTPPROXY_H
