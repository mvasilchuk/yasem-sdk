#include "utils.h"
#include "macros.h"

using namespace yasem;
using namespace yasem::SDK;

Utils::Utils()
{

}

/**
 * @brief print_data_splitter
 * Prints line with or without a text and fills all all other symbols with value.
 *
 * @param text text in the middle of a line
 * @param len max line length
 * @param value value to fill the line with
 */
void Utils::print_data_splitter(const QString &text, const quint8 len, const char value)
{
    const int text_len = text.length();
    if(text_len == 0)
    {
        DEBUG() << qPrintable(QString(value).repeated(len));
        DEBUG(); // Empty string below footer
    }
    else if(text.length() < len)
    {
        const quint8 left_len = (len - text_len) / 2;
        const int diff = len - left_len - text_len - left_len - 2; // 2 is for spaces
        quint8 right_len = left_len + diff;

        DEBUG(); // Empty string above header
        DEBUG() << qPrintable(
                       QString("%1 %2 %3")
                        .arg(QString(value).repeated(left_len))
                        .arg(text)
                        .arg(QString(value).repeated(right_len))
                       );
    }
    else
    {
        DEBUG(); // Empty string above header
        DEBUG() << qPrintable(text);
    }
}

