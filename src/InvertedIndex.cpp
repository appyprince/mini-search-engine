#include "../include/InvertedIndex.h"

void InvertedIndex::addWord(const string& word, int documentId)
{
    index[word][documentId]++;
}

void InvertedIndex::addDocument(const vector<string>& words, int documentId)
{
    for (const string& word : words)
    {
        addWord(word, documentId);
    }
}

bool InvertedIndex::contains(const string& word) const
{
    return index.find(word) != index.end();
}

unordered_map<int, int> InvertedIndex::search(const string& word) const
{
    auto it = index.find(word);

    if (it == index.end())
        return {};

    return it->second;
}