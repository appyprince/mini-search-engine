#include "../include/Document.h"

Document::Document(int id, const string& filename, const string& filepath)
{
    this->id = id;
    this->filename = filename;
    this->filepath = filepath;
}

int Document::getId() const
{
    return id;
}

const string& Document::getFilename() const
{
    return filename;
}

const string& Document::getFilepath() const
{
    return filepath;
}