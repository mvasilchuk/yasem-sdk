#include "profilemanager.h"
#include "macros.h"

using namespace yasem;
using namespace SDK;


ProfileManager::ProfileManager(QObject *parent):
    QObject(parent),
    m_active_profile(NULL)
{

}

ProfileManager::~ProfileManager()
{
    STUB();
}
