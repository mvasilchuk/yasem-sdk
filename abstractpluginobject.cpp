#include "abstractpluginobject.h"
#include "macros.h"

using namespace yasem;
using namespace SDK;


AbstractPluginObject::AbstractPluginObject(Plugin *plugin):
    QObject((QObject*)plugin),
    m_plugin(plugin),
    m_is_initialized(false)
{

}

AbstractPluginObject::~AbstractPluginObject()
{
    //STUB();
}

void AbstractPluginObject::setInitialized(bool value)
{
    m_is_initialized = value;
}

bool AbstractPluginObject::isInitialized()
{
    return m_is_initialized;
}

Plugin *AbstractPluginObject::plugin()
{
    return m_plugin;
}
