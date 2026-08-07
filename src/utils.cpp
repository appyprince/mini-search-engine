#include "utils.h"
#include <cctype>

std::string clean_word(const std::string& word)
{
    std::string cleaned;

    for (char c : word)
    {
        if (!std::ispunct(static_cast<unsigned char>(c)))
        {
            cleaned += static_cast<char>(
                std::tolower(static_cast<unsigned char>(c))
            );
        }
    }

    return cleaned;
}