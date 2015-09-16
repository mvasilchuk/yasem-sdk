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

}

void WebPage::setId(const QString &id)
{
    d_ptr->m_id = id;
}

QString WebPage::getId() const
{
    return d_ptr->m_id;
}
