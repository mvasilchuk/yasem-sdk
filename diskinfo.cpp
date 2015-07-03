#include "diskinfo.h"

using namespace yasem::SDK;

QString StorageInfo::toString()
{
    return QString("disk: [%1, %2, %3, %4, %5, %6, %7, %8]")
            .arg(blockDevice)
            .arg(mountPoint)
            .arg(size)
            .arg(used)
            .arg(available)
            .arg(percentComplete)
            .arg(vendor)
            .arg(model);
}
