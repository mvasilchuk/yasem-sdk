#include "gui.h"
#include "macros.h"

#include <QMetaEnum>

using namespace yasem;
using namespace yasem::SDK;


GUI *GUI::instance()
{
    GUI* gui = __get_plugin<GUI*>(ROLE_GUI);
    Q_ASSERT(gui);
    return gui;
}

QString GUI::getRcKeyName(GUI::RcKey key) const
{
    int index = metaObject()->indexOfEnumerator("RcKey");
    QMetaEnum metaEnum = metaObject()->enumerator(index);
    return metaEnum.valueToKey(key);
}

GUI::RcKey GUI::getRcKeyByName(const QString &name) const
{
    int index = metaObject()->indexOfEnumerator("RcKey");
    QMetaEnum metaEnum = metaObject()->enumerator(index);
    return (RcKey)metaEnum.keyToValue(name.toUtf8().constData());
}
