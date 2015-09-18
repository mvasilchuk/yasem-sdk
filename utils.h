#ifndef UTILS_H
#define UTILS_H

#include <QString>

#define MAX_LINE_LENGTH 80
#define PRINT_DATA_HEADER(header)   SDK::Utils::print_data_splitter(header)
#define PRINT_DATA_FOOTER           SDK::Utils::print_data_splitter()

namespace yasem {

namespace SDK {

class Utils
{
public:
    Utils();

    static void print_data_splitter(const QString& text = "",
                                    const quint8 len = MAX_LINE_LENGTH,
                                    const char value = '-');

};

}

}



#endif // UTILS_H
