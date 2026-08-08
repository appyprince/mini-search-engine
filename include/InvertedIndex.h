#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class InvertedIndex
{
private:
    unordered_map<string, unordered_map<int, int>> index;

public:
    void addWord(const string& word, int documentId);
    void addDocument(const vector<string>& words, int documentId);

    bool contains(const string& word) const;

    unordered_map<int, int> search(const string& word) const;
};