#include "utils.h"
using namespace std;

#include <filesystem>

namespace fs = filesystem;

int main()
{
    string dataset_path = ".././dataset";

    // The Inverted Index: Word -> Set of File Paths
    unordered_map<string, unordered_map<int, int>> inverted_index;
    unordered_map<int, string> document_map;
    int document_id = 0;

    cout << "Indexing files...\n";

    // 1. Traverse the directory
    for (const auto &entry : fs::directory_iterator(dataset_path))
    {
        string filepath = entry.path().string();

        // This prevents accidentally trying to read directories.
        if (!entry.is_regular_file())
            continue;

        string filename = entry.path().filename().string();
        document_map[document_id] = filename;

        // 2. Open the file
        ifstream file(filepath);
        if (!file.is_open())
        {
            cout << "Could not open file: " << filepath << "\n";
            continue;
        }

        string raw_word;
        // 3. Read word by word
        while (file >> raw_word)
        {
            string processed_word = clean_word(raw_word);

            // Only add to index if the word isn't empty after cleaning
            if (!processed_word.empty())
            {
                inverted_index[processed_word][document_id]++;
            }
        }
        file.close();
        document_id++;
    }

    // 4. The Search Loop
    cout << "Indexing complete! Type 'exit' to quit.\n";
    while (true)
    {
        cout << "\nEnter a word to search: ";
        string query;
        cin >> query;

        if (query == "exit")
            break;

        // Clean the user's query so it matches the index format
        query = clean_word(query);

        // Look it up in the hash map
        if (inverted_index.find(query) != inverted_index.end())
        {
            cout << "Found '" << query << "' in:\n";
            for (const auto &pair : inverted_index[query])
            {
                int doc_id = pair.first;
                int frequency = pair.second;

                string filename = document_map[doc_id];

                cout << filename
                     << " , " << doc_id
                     << " , " << frequency << "\n";
            }
        }
        else
        {
            cout << "No results found for '" << query << "'.\n";
        }
    }

    return 0;
}