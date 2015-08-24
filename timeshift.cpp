#include "timeshift.h"
#include "pluginmanager.h"

using namespace yasem;
using namespace SDK;

TimeShift::TimeShift(Plugin *plugin):
    SDK::AbstractPluginObject(plugin)
{

}

TimeShift::~TimeShift()
{

}

bool yasem::SDK::TimeShift::isAvailable()
{
    return instance() != NULL;
}

TimeShift* TimeShift::instance()
{
    static TimeShift* inst = 0;
    if(!inst)
        inst = PluginManager::getByRole<SDK::TimeShift>(ROLE_TIMESHIFT);
    return inst;
}

void TimeShift::setInputURL(const QUrl &url)
{
    m_input_url = url;
    emit inputUrlChanged(url);
}

QUrl TimeShift::getInputURL() const
{
    return m_input_url;
}

QUrl TimeShift::getOutputURL() const
{
    return m_output_url;
}

void TimeShift::setOutputUrl(const QUrl &url)
{
    m_output_url = url;
    emit outputUrlChanged(url);
}
