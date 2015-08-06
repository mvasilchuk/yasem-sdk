#ifndef IPLUGINMANAGER_H
#define IPLUGINMANAGER_H

#include "enums.h"

#include <QObject>
#include <QList>
#include <QStringList>
#include <QJsonArray>
#include <QCoreApplication>
#include <QVariant>
#include <QHash>

namespace yasem {
namespace SDK {

class AbstractPluginObject;
class Plugin;

struct PluginRoleData {

    PluginRoleData();

    PluginRoleData(const QString &name, const QString &description, QList<PluginRole> conflicts_with = QList<PluginRole>());

    PluginRoleData(const PluginRoleData& other);

    QString m_name;
    QString m_description;
    QList<PluginRole> m_conflicts_with;

};

class PluginManager : public QObject
{
    Q_OBJECT
public:
    static PluginManager* setInstance(PluginManager* inst = 0);

    static PluginManager* instance();

    virtual PluginErrorCodes listPlugins() = 0;
    virtual PluginErrorCodes initPlugins() = 0;
    virtual PluginErrorCodes deinitPlugins() = 0;
    //virtual PLUGIN_ERROR_CODES connectSlots();
    virtual QList<QSharedPointer<Plugin>> getPlugins(PluginRole role, bool active_only) = 0;
    virtual AbstractPluginObject* getByRole(PluginRole role, bool show_warning = true) const = 0;
    virtual QSharedPointer<Plugin> getByIID(const QString &iid) = 0;
    virtual void setPluginDir(const QString &pluginDir) = 0;
    virtual QString getPluginDir() = 0;

    //virtual void loadProfiles() = 0;
protected:
    PluginManager(QObject* parent);
    virtual ~PluginManager();

    virtual PluginFlag parseFlags(const QString &flagsStr) = 0;
    virtual void registerPluginRole(const PluginRole& role, const PluginRoleData& data) = 0;

private:

    // Dont forget to declare these two. You want to make sure they
    // are unaccessable otherwise you may accidently get copies of
    // your singleton appearing.
    PluginManager(PluginManager const&);              // Don't Implement
    void operator=(PluginManager const&); // Don't implement
};

}

}


#endif // IPLUGINMANAGER_H
