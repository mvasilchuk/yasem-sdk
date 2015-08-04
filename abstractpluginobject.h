#ifndef ABSTRACTPLUGINOBJECT
#define ABSTRACTPLUGINOBJECT

#include <QObject>

namespace yasem {
namespace SDK {

class Plugin;

enum PluginObjectResult {
    PLUGIN_OBJECT_RESULT_OK,
    PLUGIN_OBJECT_RESULT_ERROR,
};

class AbstractPluginObject: public QObject
{
    Q_OBJECT
public:
    explicit AbstractPluginObject(Plugin* plugin);

    virtual ~AbstractPluginObject();

    virtual PluginObjectResult init() = 0;
    virtual PluginObjectResult deinit() = 0;

    void setInitialized(bool value);

    bool isInitialized();

    Plugin* plugin();

protected:
    Plugin* m_plugin;
    bool m_is_initialized;
};
}
}

#endif // ABSTRACTPLUGINOBJECT

