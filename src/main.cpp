#include "../include/SearchEngine.h"

#include <iostream>

using namespace std;

int main()
{
    SearchEngine searchEngine;

    searchEngine.indexDirectory("dataset");

    while (true)
    {
        string query;

        cout << "Search: ";
        getline(cin, query);

        if (query == "exit")
            break;

        vector<SearchResult> results =
            searchEngine.search(query);

        if (results.empty())
        {
            cout << "No results found.\n";
            continue;
        }

        for (const SearchResult& result : results)
        {
            cout << "Document ID: "
                 << result.documentId
                 << " | Frequency: "
                 << result.frequency
                 << '\n';
        }
    }

    return 0;
}