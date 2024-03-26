#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, long> buildIndex(const string &filename) {
    ifstream file(filename);
    map<string, long> index;
    string line;
    long position = 0;

    if (!file) {
        cerr << "ERROR openin file: " << filename << endl;
        return index;
    }

    while (getline(file, line)) {
        index[line.substr(0, line.find(' '))] = file.tellg();
    }

    file.close();
    return index;
}

void searchByKey(const string &filename, const map<string, long> &index,
                 const string &key) {
    auto it = index.find(key);
    if (it == index.end()) {
        cout << "Key not found." << endl;
        return;
    }

    ifstream file(filename);
    file.seekg(it->second);
    string line;
    getline(file, line);
    cout << "Record: " << line << endl;

    file.close();
}