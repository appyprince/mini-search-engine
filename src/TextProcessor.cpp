#include "../include/TextProcessor.h"

#include <cctype>

string TextProcessor::cleanWord(const string& word)
{
    string result;
    string banned_word = ".,<>!(){}[]\"'";

    for (char c : word)
    {
        if (banned_word.find(c)==string::npos && !isspace(c)){
            result += tolower(c);}
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