#ifndef PLUGINDEPENDENCY_H
#define PLUGINDEPENDENCY_H

#include "enums.h"
#include <QObject>

namespace yasem {
namespace SDK {

class Plugin;

class PluginDependency
{
    Q_GADGET
public:
    PluginDependency(QString name, bool required = true, bool skip_if_failed = false);
    PluginDependency(PluginRole role, bool required = true, bool skip_if_failed = false);
    PluginDependency(QString name, PluginRole role, bool required = true, bool skip_if_failed = false);

    QString roleName() const;

    bool isRequired() const;
    PluginRole getRole() const;
    QString getDependencyName() const;
    bool doSkipIfFailed()  const;

protected:
    QString m_dependency_name; // A name of registered plugin dependency
    PluginRole m_role;         // A role of a dependency.
                               // You should declare at least one of dependency_name or role (or both).
    bool m_required;           // Set this flag if plugin cannot be loaded without this dependency.
    bool m_skip_if_failed;

    void init(const QString& dependency_name, const bool required, const PluginRole role, bool skip_if_failed);
};

}

}

#endif // PLUGINDEPENDENCY_H
