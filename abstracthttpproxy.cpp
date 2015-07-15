#include "abstracthttpproxy.h"
#include "abstracthttpproxy_p.h"

using namespace yasem::SDK;

HttpProxy::HttpProxy(Plugin* plugin):
    AbstractPluginObject(plugin),
    d_ptr(new HttpProxyPrivate(this))
{

}

HttpProxy::~HttpProxy()
{

}

void HttpProxy::setHostHame(const QString &host_name)
{
    Q_D(HttpProxy);
    d->m_host_name = host_name;
}

QString HttpProxy::hostName()
{
    Q_D(HttpProxy);
    return d->m_host_name;
}

void HttpProxy::setPort(quint16 port)
{
    Q_D(HttpProxy);
    d->m_port = port;
}

quint16 HttpProxy::port()
{
    Q_D(HttpProxy);
    return d->m_port;
}

void HttpProxy::setMaxRequestPerSecond(quint16 max_rps)
{
    Q_D(HttpProxy);
    d->m_max_rps = max_rps;
}

quint16 HttpProxy::getMaxRequestPerSecond()
{
    Q_D(HttpProxy);
    return d->m_max_rps;
}

bool HttpProxy::isRpsLimited()
{
    Q_D(HttpProxy);
    return d->m_max_rps > 0;
}

