#pragma once

#include <string>
#include <vector>

using namespace std;

class TextProcessor
{
public:
    string cleanWord(const string& word);
    vector<string> tokenize(const string& text);
};