#include "webpage_p.h"

using namespace yasem;
using namespace yasem::SDK;

WebPagePrivate::WebPagePrivate(WebPage* page):
    q_ptr(page),
    m_id("-not-specified-")
{

}

WebPagePrivate::~WebPagePrivate()
{

}
