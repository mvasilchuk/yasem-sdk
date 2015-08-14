#include "plugin.h"
#include "plugin_p.h"
#include "abstractpluginobject.h"
#include "crashhandler.h"

#include <QMetaClassInfo>

using namespace yasem::SDK;

Plugin::Plugin(QObject* parent):
    QObject(parent),
    d_ptr(new PluginPrivate(this))
{
#ifdef USE_BREAKPAD
    Breakpad::CrashHandler::instance()->init();
#endif //USE_BREAKPAD
}

Plugin::~Plugin()
{
    //STUB();
    delete d_ptr;
}

bool Plugin::hasFlag(PluginFlag flag)
{
    return (getFlags() & flag) == flag;
}

void Plugin::addFlag(PluginFlag flag)
{
    this->setFlags((PluginFlag)(getFlags() | flag));
}

PluginErrorCodes Plugin::initialize()
{
    for(AbstractPluginObject* obj: roles().values())
    {
        obj->init();
        obj->setInitialized(true);
    }
    return PLUGIN_ERROR_NO_ERROR;
}

PluginErrorCodes Plugin::deinitialize()
{
    for(AbstractPluginObject* obj: roles().values())
    {
        obj->deinit();
        obj->setInitialized(false);
    }
    return PLUGIN_ERROR_NO_ERROR;
}

bool Plugin::has_role(PluginRole role)
{
    Q_D(Plugin);
    return d->m_role_list.contains(role);
}

QHash<PluginRole, AbstractPluginObject*> Plugin::roles() const
{
    return d_ptr->m_role_list;
}

QList<PluginDependency> Plugin::dependencies() const
{
    return d_ptr->m_dependency_list;
}

QString Plugin::getIID() const
{
    return d_ptr->m_IID;
}

void Plugin::setIID(const QString &iid)
{
    Q_D(Plugin);
    d->m_IID = iid;
}

QString Plugin::getClassName() const
{
    return d_ptr->m_className;
}

void Plugin::setClassName(const QString &className)
{
    Q_D(Plugin);
    d->m_className = className;
}

QString Plugin::getId() const
{
    return d_ptr->m_id;
}

void Plugin::setId(const QString &id)
{
    Q_D(Plugin);
    d->m_id = id;
}

QString Plugin::getVersion() const
{
    return metaObject()->classInfo(metaObject()->indexOfClassInfo("version")).value();
}

QString Plugin::getRevision() const
{
    return metaObject()->classInfo(metaObject()->indexOfClassInfo("revision")).value();
}

QString Plugin::getName() const
{
    return d_ptr->m_name;
}

void Plugin::setName(const QString &name)
{
    Q_D(Plugin);
    d->m_name = name;
}

QJsonObject Plugin::getMetadata() const
{
    return d_ptr->m_metadata;
}

void Plugin::setMetadata(const QJsonObject &metadata)
{
    Q_D(Plugin);
    d->m_metadata = metadata;
}

PluginFlag Plugin::getFlags() const
{
    return d_ptr->m_flags;
}

void Plugin::setFlags(const PluginFlag &flags)
{
    Q_D(Plugin);
    d->m_flags = flags;
}

PluginState Plugin::getState() const
{
    return d_ptr->m_state;
}

void Plugin::setState(const PluginState &state)
{
    Q_D(Plugin);
    d->m_state = state;

    switch(state)
    {
        case PLUGIN_STATE_INITIALIZED:              { emit initialized();               break; }
        case PLUGIN_STATE_NOT_INITIALIZED:          { emit deinitialized();             break; }
        case PLUGIN_STATE_CONFLICT:                 { emit got_conflict();              break; }
        case PLUGIN_STATE_DISABLED:                 { emit disabled();                  break; }
        case PLUGIN_STATE_ERROR_STATE:              { emit error_happened();            break; }
        case PLUGIN_STATE_DISABLED_BY_DEPENDENCY:   { emit disabled_by_dependency();    break; }
        case PLUGIN_STATE_WAITING_FOR_DEPENDENCY:   { emit waiting_for_dependency();    break; }
        case PLUGIN_STATE_THREAD_CREATING:          { emit plugin_thread_starting();    break; }
        case PLUGIN_STATE_THREAD_STARTED:           { emit plugin_thread_started();     break; }
        default: {
            WARN() << "Unknown plugin state" << state << "for" << getName();
            break;
        }
    }
}

QString Plugin::getStateDescription() const
{
    QString result;
    const PluginState state = getState();
    switch(state)
    {
        case PLUGIN_STATE_UNKNOWN:                  { result = "Unknown"; break; }
        case PLUGIN_STATE_ERROR_STATE:              { result = "Error"; break; }
        case PLUGIN_STATE_INITIALIZED:              { result = "Working"; break; }
        case PLUGIN_STATE_NOT_INITIALIZED:          { result = "Not initialized"; break; }
        case PLUGIN_STATE_WAITING_FOR_DEPENDENCY:   { result = "Wait4dependency"; break; }
        case PLUGIN_STATE_DISABLED:                 { result = "Disabled"; break; }
        case PLUGIN_STATE_CONFLICT:                 { result = "Conflict"; break; }
        case PLUGIN_STATE_DISABLED_BY_DEPENDENCY:   { result = "Disabled by dep."; break; }
        case PLUGIN_STATE_THREAD_STARTED:           { result = "Thread started."; break; }
        default:                                    { result = QString::number(state); break; }
    }
    return result;
}

bool Plugin::isActive() const
{
    return d_ptr->m_active;
}

void Plugin::setActive(bool active)
{
    Q_D(Plugin);
    d->m_active = active;
}

QList<QSharedPointer<Plugin>> Plugin::getRuntimeConflicts() const
{
    return d_ptr->m_runtime_conflicts;
}

void Plugin::addRuntimeConflict(QSharedPointer<Plugin> plugin)
{
    Q_D(Plugin);
    d->m_runtime_conflicts.append(plugin);
}

QList<PluginConflict> Plugin::getStaticConflicts() const
{
    return d_ptr->m_static_conflicts;
}

bool Plugin::isMultithreadingEnabled()
{
    Q_D(Plugin);
    return d->m_multithreading_enabled;
}

void Plugin::add_dependency(const PluginDependency& dependency)
{
    Q_D(Plugin);
    d->m_dependency_list.append(dependency);
}

void Plugin::add_static_conflict(const PluginConflict &conflict_info)
{
    Q_D(Plugin);
    d->m_static_conflicts.append(conflict_info);
}

void Plugin::register_role(PluginRole role, AbstractPluginObject* obj)
{
    Q_D(Plugin);
    d->m_role_list.insert(role, obj);
}

void Plugin::setMultithreading(bool enable)
{
    Q_D(Plugin);
    d->m_multithreading_enabled = enable;
}

PluginPrivate::~PluginPrivate()
{
    STUB() << this;
    /*QMutableHashIterator<PluginRole, QSharedPointer<AbstractPluginObject>> iter(m_role_list);
    while(iter.hasNext())
    {
        iter.next();

        iter.
    }*/
}
