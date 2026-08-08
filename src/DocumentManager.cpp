#include "../include/DocumentManager.h"

int DocumentManager::addDocument(const string& filename, const string& filepath)
{
    int id = documents.size();

    documents.emplace_back(id, filename, filepath);

    return id;
}

Document* DocumentManager::getDocument(int id)
{
    if (id < 0 || id >= documents.size())
        return nullptr;

    return &documents[id];
}

const vector<Document>& DocumentManager::getAllDocuments() const
{
    return documents;
}