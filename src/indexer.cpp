#include"utils.h"
#include<bits/stdc++.h>
using namespace std;

#include <filesystem>

namespace fs = std::filesystem;

string clean_word(const string& word) {
    string cleaned = "";
    for (char c : word) {
        // Keep the character only if it's NOT punctuation
        if (!ispunct(c)) {
            cleaned += tolower(c); // Convert to lowercase
        }
    }
    return cleaned;
}

int main() {
    string dataset_path = "D:/my_search_engine/dataset"; 
    
    // The Inverted Index: Word -> Set of File Paths
    unordered_map<string, unordered_set<string>> inverted_index;

    cout << "Indexing files...\n";

    // 1. Traverse the directory
    for (const auto& entry : fs::directory_iterator(dataset_path)) {
        string filepath = entry.path().string();
        
        // 2. Open the file
        ifstream file(filepath);
        if (!file.is_open()) {
            cout << "Could not open file: " << filepath << "\n";
            continue;
        }

        string raw_word;
        // 3. Read word by word
        while (file >> raw_word) {
            string processed_word = clean_word(raw_word);
            
            // Only add to index if the word isn't empty after cleaning
            if (!processed_word.empty()) {
                inverted_index[processed_word].insert(filepath);
            }
        }
        file.close();
    }

    // 4. The Search Loop
    cout << "Indexing complete! Type 'exit' to quit.\n";
    while (true) {
        cout << "\nEnter a word to search: ";
        string query;
        cin >> query;

        if (query == "exit") break;

        // Clean the user's query so it matches the index format
        query = clean_word(query);

        // Look it up in the hash map
        if (inverted_index.find(query) != inverted_index.end()) {
            cout << "Found '" << query << "' in:\n";
            for (const string& path : inverted_index[query]) {
                cout << " -> " << path << "\n";
            }
        } else {
            cout << "No results found for '" << query << "'.\n";
        }
    }

    return 0;
}