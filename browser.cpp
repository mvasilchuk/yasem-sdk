#include "browser.h"
#include "macros.h"

using namespace yasem;
using namespace SDK;


Browser::Browser(Plugin *plugin):
    AbstractPluginObject(plugin)
{

}

Browser::~Browser()
{
    m_use_qml = false;
    STUB();
}

Browser *Browser::instance()
{
    static Browser* inst = 0;
    if(!inst)
        inst = PluginManager::getByRole<SDK::Browser>(ROLE_BROWSER);
    if(!inst)
        WARN() << "Browser not found!";
    return inst;
}

QString Browser::getQmlComponentName()
{
    return "";
}

void Browser::setUseQml(bool use)
{
    m_use_qml = use;
}

bool Browser::isUsingQml() const
{
    return m_use_qml;
}

void Browser::setTopWidget(Browser::TopWidget top)
{
    m_top_widget = top;
    emit topWidgetChanged();
}

Browser::TopWidget Browser::getTopWidget()
{
    return m_top_widget;
}

void Browser::showDeveloperTools()
{
    DEBUG() << "Developer tools are not supported by this browser!";
}
