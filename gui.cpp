#include "gui.h"
#include "plugin.h"
#include "macros.h"

using namespace yasem;
using namespace yasem::SDK;


GUI *GUI::instance()
{
    GUI* gui = __get_plugin<GUI*>(ROLE_GUI);
    Q_ASSERT(gui);
    return gui;
}
