#include "gui.h"
#include "macros.h"
#include "browser.h"
#include "webpage.h"
#include "mediaplayer.h"

#include <QMetaEnum>
#include <QVariant>

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

void GUI::setTopWidget(TopWidget top)
{
    m_top_widget = top;
    switch(m_top_widget)
    {
        case TOP_WIDGET_BROWSER:
        {
            WebPage* page = Browser::instance()->getMainWebPage();
            DEBUG() << "raising web page" << dynamic_cast<QObject*>(page);
            page->raise();
            break;
        }
        case TOP_WIDGET_PLAYER:
        {
            QWidget* widget = MediaPlayer::instance()->widget();
            DEBUG() << "raising player" << widget;
            widget->raise();
            break;
        }
        default: {
            DEBUG() << "raising unknown";
            break;
        }
    }
    emit topWidgetChanged();

    widgetStack();
}

GUI::TopWidget GUI::getTopWidget()
{
    return m_top_widget;
}

const QObjectList &GUI::widgetStack() const
{
    const QObjectList& list = Browser::instance()->getMainWebPage()->widget()->parentWidget()->children();
    DEBUG() << "Current widget stack:";
    for(QObject* object: list)
    {
        QWidget* widget = qobject_cast<QWidget*>(object);
        if(widget)
        {
            DEBUG() << qPrintable(
                   QString("Child: %1 [visibility: %2]")
                          .arg(widget->objectName())
                          .arg(widget->isVisible() ? "visible" : "hidden")
            );
        }

    }
    return list;
}
