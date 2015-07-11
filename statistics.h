#ifndef STATISTICS
#define STATISTICS

#include <QObject>
#include <QList>

namespace yasem {
namespace SDK {

class NetworkStatistics;
class SystemStatistics;

class Statistics: public QObject
{
    Q_OBJECT
public:
    Statistics(QObject* parent): QObject(parent) {}

    virtual NetworkStatistics* network() const = 0;
    virtual SystemStatistics* system() const = 0;
};

}

}

#endif // STATISTICS

