#include "../include/TextProcessor.h"

#include <cctype>

string TextProcessor::cleanWord(const string& word)
{
    string result;

    for (char c : word)
    {
        if (isalnum(static_cast<unsigned char>(c)))
            result += tolower(static_cast<unsigned char>(c));
    }

    return result;
}

vector<string> TextProcessor::tokenize(const string& text)
{
    vector<string> words;
    string word;

    for (char c : text)
    {
        if (isspace(static_cast<unsigned char>(c)))
        {
            if (!word.empty())
            {
                string cleaned = cleanWord(word);

                if (!cleaned.empty())
                    words.push_back(cleaned);

                word.clear();
            }
        }
        else
        {
            word += c;
        }
    }

    if (!word.empty())
    {
        string cleaned = cleanWord(word);

        if (!cleaned.empty())
            words.push_back(cleaned);
    }

    return words;
}