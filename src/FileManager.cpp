#include "../include/FileManager.h"

#include <filesystem>
#include <fstream>
#include <sstream>

vector<string> FileManager::getFiles(const string& directory)
{
    vector<string> files;

    for (const auto& entry : filesystem::directory_iterator(directory))
    {
        if (entry.is_regular_file())
            files.push_back(entry.path().string());
    }

    return files;
}

string FileManager::readFile(const string& filepath)
{
    ifstream file(filepath);

    if (!file.is_open())
        return "";

    stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}