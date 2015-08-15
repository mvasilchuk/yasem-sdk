#include "gui.h"
#include "macros.h"

#include <QMetaEnum>

using namespace yasem;
using namespace yasem::SDK;


GUI* GUI::instance()
{
    static GUI* inst = 0;
    if(!inst)
        inst = PluginManager::getByRole<SDK::GUI>(ROLE_GUI);
    if(!inst)
        WARN() << "GUI not found!";
    return inst;
}

QString GUI::getRcKeyName(GUI::RcKey key) const
{
    const int index = metaObject()->indexOfEnumerator("RcKey");
    const QMetaEnum metaEnum = metaObject()->enumerator(index);
    return metaEnum.valueToKey(key);
}

GUI::RcKey GUI::getRcKeyByName(const QString &name) const
{
    const int index = metaObject()->indexOfEnumerator("RcKey");
    const QMetaEnum metaEnum = metaObject()->enumerator(index);
    return (RcKey)metaEnum.keyToValue(name.toUtf8().constData());
}
