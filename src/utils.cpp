#include "utils.h"
#include <cctype>

string clean_word(const string& word)
{
    std::string cleaned;

    for (char c : word)
    {
        if (!ispunct(static_cast<unsigned char>(c)))
        {
            cleaned += static_cast<char>(
                tolower(static_cast<unsigned char>(c))
            );
        }
    }

    return cleaned;
}