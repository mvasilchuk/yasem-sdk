#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>
#include <QVariant>

namespace yasem {
namespace SDK {

class Datasource: public QObject
{
    Q_OBJECT
public:
    Datasource(QObject* parent);
    virtual ~Datasource();


public slots:
    virtual int get(const QString &tag, const QString &name, const int defaultValue)  = 0;
    virtual QString get(const QString &tag, const QString &name, const QString &defaultValue = "")  = 0;

    virtual bool set(const QString &tag, const QString &name, const int value) = 0;
    virtual bool set(const QString &tag, const QString &name, const QString &value)  = 0;

    virtual void beginGroup(const QString& group) = 0;
    virtual void endGroup() = 0;

    virtual void setValue(const QString &key, const QVariant &value) = 0;
    virtual QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const = 0;

    virtual QStringList allKeys() const = 0;
};

}
}



#endif // DATASOURCE_H
