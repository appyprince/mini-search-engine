#pragma once

#include <string>
#include <vector>

#include "FileManager.h"
#include "TextProcessor.h"
#include "DocumentManager.h"
#include "InvertedIndex.h"

using namespace std;

struct SearchResult
{
    int documentId;
    int frequency;
};

class SearchEngine
{
private:
    FileManager fileManager;
    TextProcessor textProcessor;
    DocumentManager documentManager;
    InvertedIndex invertedIndex;

public:
    void indexDirectory(const string& directory);

    vector<SearchResult> search(const string& query);
};