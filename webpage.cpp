#include "webpage.h"
#include "webpage_p.h"
#include "macros.h"

using namespace yasem;
using namespace SDK;


WebPage::WebPage():
    d_ptr(new WebPagePrivate(this))
{

}

WebPage::~WebPage()
{
    delete d_ptr;
}


void WebPage::setId(const int id)
{
    d_ptr->m_id = id;
}

int WebPage::getId() const
{
    return d_ptr->m_id;
}
