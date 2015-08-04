#include "pluginmanager.h"
#include "macros.h"
#include "plugin.h"

using namespace yasem;
using namespace SDK;


PluginManager *PluginManager::setInstance(PluginManager *inst)
{
    static PluginManager* instance = inst;// Guaranteed to be destroyed.

    if(instance == NULL)
        instance = static_cast<PluginManager*>(qApp->property("PluginManager").value<QObject*>());

    Q_CHECK_PTR(instance);
    return instance;
}

PluginManager *PluginManager::instance()
{
    return setInstance();
}

PluginManager::PluginManager(QObject *parent):
    QObject(parent)
{

}

PluginManager::~PluginManager()
{
    //STUB();
}


PluginRoleData::PluginRoleData()
{

}

PluginRoleData::PluginRoleData(const QString &name, const QString &description, QList<PluginRole> conflicts_with)
    :m_name(name),
      m_description(description),
      m_conflicts_with(conflicts_with)
{

}

PluginRoleData::PluginRoleData(const PluginRoleData &other)
    :m_name(other.m_name),
      m_description(other.m_description),
      m_conflicts_with(other.m_conflicts_with)
{
}
