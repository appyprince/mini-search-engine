#include "../include/SearchEngine.h"

#include <filesystem>

vector<SearchResult> SearchEngine::search(const string& query)
{
    vector<SearchResult> results;

    vector<string> words = textProcessor.tokenize(query);

    if (words.empty())
        return results;

    string word = words[0];

    unordered_map<int, int> matches = invertedIndex.search(word);

    for (const auto& entry : matches)
    {
        SearchResult result;

        result.documentId = entry.first;
        result.frequency = entry.second;

        results.push_back(result);
    }

    return results;
}

void SearchEngine::indexDirectory(const string& directory)
{
    vector<string> files = fileManager.getFiles(directory);

    for (const string& filepath : files)
    {
        string text = fileManager.readFile(filepath);

        if (text.empty())
            continue;

        filesystem::path path(filepath);

        string filename = path.filename().string();

        int documentId =
            documentManager.addDocument(filename, filepath);

        vector<string> words = textProcessor.tokenize(text);

        invertedIndex.addDocument(words, documentId);
    }
}