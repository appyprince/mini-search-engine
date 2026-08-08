#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

using namespace std;

class Document
{
private:
    int id;
    string filename;
    string filepath;

public:
    Document(int id, const string& filename, const string& filepath);

    int getId() const;
    const string& getFilename() const;
    const string& getFilepath() const;
};

#endif