#include "browser.h"
#include "macros.h"

using namespace yasem;
using namespace SDK;


Browser::Browser(Plugin *plugin):
    AbstractPluginObject(plugin),
    m_last_page_id(0),
    m_window_open_requested(false)
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

int Browser::nextPageId()
{
    m_last_page_id++;
    DEBUG() << "New page ID:" << m_last_page_id;
    return m_last_page_id;
}

void Browser::resetPageIds()
{
    m_last_page_id = 0;
}

int Browser::lastPageId() const
{
    return m_last_page_id;
}

void Browser::setWindowOpenRequested(bool value)
{
    m_window_open_requested = value;
}

bool Browser::isWindowOpenRequested() const
{
    return m_window_open_requested;
}

void Browser::showDeveloperTools()
{
    DEBUG() << "Developer tools are not supported by this browser!";
}
