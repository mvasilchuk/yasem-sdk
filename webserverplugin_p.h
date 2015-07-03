#ifndef WEBSERVERPLUGIN_P
#define WEBSERVERPLUGIN_P

#include <QString>

namespace yasem {
namespace SDK {

class WebServerPlugin;
class WebServerPluginPrivate
{
public:
    explicit WebServerPluginPrivate(WebServerPlugin* q) :
        q_ptr(q),
        m_rootDirectory("")
    {
    }

    virtual ~WebServerPluginPrivate() {}
protected:
    WebServerPlugin *q_ptr;
public:
    QString m_rootDirectory;
};

}

}

#endif // WEBSERVERPLUGIN_P

