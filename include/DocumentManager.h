#pragma once

#include <vector>
#include <string>
#include "Document.h"

using namespace std;

class DocumentManager
{
private:
    vector<Document> documents;

public:
    int addDocument(const string& filename, const string& filepath);

    Document* getDocument(int id);

    const vector<Document>& getAllDocuments() const;
};