#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set> // Better than vector to avoid duplicate file paths
#include <filesystem>
#include <cctype> // For tolower() and ispunct()
using namespace std;
string clean_word(const string& word);