#include "plugindependency.h"

using namespace yasem;
using namespace yasem::SDK;


PluginDependency::PluginDependency(QString name, bool required, bool skip_if_failed)
{
    init(name, required, ROLE_UNKNOWN, skip_if_failed);
}

PluginDependency::PluginDependency(PluginRole role, bool required, bool skip_if_failed)
{
    init("", required, role, skip_if_failed);
}

PluginDependency::PluginDependency(QString name, PluginRole role, bool required, bool skip_if_failed)
{
    init(name, required, role, skip_if_failed);
}

QString PluginDependency::roleName() const
{
    switch(m_role)
    {
        case ROLE_UNKNOWN:          { return QObject::tr("Unknown");                 }
        case ROLE_UNSPECIFIED:      { return QObject::tr("Unspecified");             }
        case ROLE_GUI:              { return QObject::tr("GUI plugin");              }
        case ROLE_MEDIA:            { return QObject::tr("Media player plugin");     }
        case ROLE_STB_API:          { return QObject::tr("STB API plugin");          }
        case ROLE_BROWSER:          { return QObject::tr("Browser plugin");          }
        case ROLE_DATASOURCE:       { return QObject::tr("Datasource plugin");       }
        case ROLE_WEB_SERVER:       { return QObject::tr("Web server plugin");       }
        case ROLE_WEB_GUI:          { return QObject::tr("Web GUI plugin");          }
        default:                    {
            return QObject::tr("Unknown plugin role");
        }
    }
}

bool PluginDependency::isRequired() const
{
    return m_required;
}

PluginRole PluginDependency::getRole() const
{
    return m_role;
}

QString PluginDependency::getDependencyName() const
{
    return m_dependency_name;
}

bool PluginDependency::doSkipIfFailed() const
{
    return m_skip_if_failed;
}

void PluginDependency::init(const QString &dependency_name, const bool required, const PluginRole role, bool skip_if_failed)
{
    this->m_dependency_name = dependency_name;
    this->m_required = required;
    this->m_role = role;
    this->m_skip_if_failed = skip_if_failed;
}
