#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>

namespace yasem {
namespace SDK {

class Datasource: public QObject
{
    Q_OBJECT
public:
    Datasource(QObject* parent);
    virtual ~Datasource();

    virtual int get(const QString &tag, const QString &name, const int defaultValue)  = 0;
    virtual QString get(const QString &tag, const QString &name, const QString &defaultValue = "")  = 0;

public slots:
    virtual bool set(const QString &tag, const QString &name, const int value) = 0;
    virtual bool set(const QString &tag, const QString &name, const QString &value)  = 0;

};

}
}



#endif // DATASOURCE_H
