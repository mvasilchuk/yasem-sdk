
#include "webserverplugin_p.h"
#include "plugin_p.h"
#include "webserverplugin.h"

using namespace yasem::SDK;


WebServerPlugin::WebServerPlugin(Plugin* plugin):
    AbstractPluginObject(plugin),
    d_ptr(new WebServerPluginPrivate(this)) {

}

WebServerPlugin::~WebServerPlugin()
{
    delete d_ptr;
}

void WebServerPlugin::setRootDirectory(const QString &dir)
{
    Q_D(WebServerPlugin);
    d->m_rootDirectory = dir;
}

QString WebServerPlugin::getRootDirectory()
{
    Q_D(WebServerPlugin);
    return d->m_rootDirectory;
}

