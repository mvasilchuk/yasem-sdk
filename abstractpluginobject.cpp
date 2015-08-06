#include "abstractpluginobject.h"
#include "macros.h"

using namespace yasem;
using namespace SDK;


AbstractPluginObject::AbstractPluginObject(Plugin* plugin):
    m_plugin(plugin),
    m_is_initialized(false)
{

}

AbstractPluginObject::~AbstractPluginObject()
{
    STUB() << this;
}

void AbstractPluginObject::setInitialized(bool value)
{
    m_is_initialized = value;
}

bool AbstractPluginObject::isInitialized() const
{
    return m_is_initialized;
}

Plugin* AbstractPluginObject::plugin() const
{
    return m_plugin;
}
