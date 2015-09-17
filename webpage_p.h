#ifndef WEBPAGEPRIVATE_H
#define WEBPAGEPRIVATE_H

#include "webpage.h"

#include <QString>

namespace yasem {

namespace SDK {

class WebPagePrivate
{
    Q_DECLARE_PUBLIC(WebPage)
public:
    explicit WebPagePrivate(WebPage* page);
    virtual ~WebPagePrivate();

    WebPage *q_ptr; // q-ptr points to the API class
    int m_id;

protected:
    WebPagePrivate(WebPage &p): q_ptr(&p) {}

};

}

}



#endif // WEBPAGEPRIVATE_H
