#pragma once

#include <string>
#include <vector>

using namespace std;

class FileManager
{
public:
    vector<string> getFiles(const string& directory);
    string readFile(const string& filepath);
};