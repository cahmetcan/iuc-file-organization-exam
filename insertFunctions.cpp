#include "funcs.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
id'ye göre sıralı şekilde eklenmesini istedim. Bu yüzden
eklemeyi yaparken id'ye göre sıralı bir şekilde eklemek için
records vektöründe yeni kaydın nereye ekleneceğini bulmak için
binary search algoritmasını kullanarak yeni kaydın ekleneceği yeri buluyoruz.
 */

vector<Record> read_records(const string &file_path) {
    vector<Record> records;
    ifstream file(file_path);
    string line;

    while (getline(file, line)) {
        Record record;
        stringstream ss(line);
        ss >> record.id >> record.name >> record.departmant;
        records.push_back(record);
    }

    file.close();
    return records;
}

void insert_record(vector<Record> &records, const Record &new_record) {
    vector<Record>::iterator it = records.begin();
    while (it != records.end() && it->id < new_record.id) {
        ++it;
    }
    records.insert(it, new_record);
}

void write_records(const string &file_path, const vector<Record> &records) {
    ofstream file(file_path);
    for (vector<Record>::const_iterator it = records.begin();
         it != records.end(); ++it) {
        file << it->id << " " << it->name << " " << it->departmant << endl;
    }
    file.close();
}

void createUser(const string &file_path) {
    vector<Record> records = read_records(file_path);

    Record new_record;
    cout << "Enter id, name, and departmant for the new record: ";
    cin >> new_record.id >> new_record.name >> new_record.departmant;
    insert_record(records, new_record);

    write_records(file_path, records);

    cout << "Record inserted successfully.\n";
}

void deleteUser(const string &file_path) {
    vector<Record> records = read_records(file_path);

    int id;
    cout << "Enter id of the record to delete: ";
    cin >> id;

    vector<Record>::iterator it = records.begin();
    while (it != records.end() && it->id != id) {
        ++it;
    }

    if (it == records.end()) {
        cout << "Record not found.\n";
        return;
    }

    records.erase(it);
    write_records(file_path, records);

    cout << "Record deleted successfully.\n";
}

void updateUser(const string &file_path) {
    vector<Record> records = read_records(file_path);

    int id;
    cout << "Enter id of the record to update: ";
    cin >> id;

    vector<Record>::iterator it = records.begin();
    while (it != records.end() && it->id != id) {
        ++it;
    }

    if (it == records.end()) {
        cout << "Record not found.\n";
        return;
    }

    cout << "Enter new name and departmant for the record: ";
    cin >> it->name >> it->departmant;

    write_records(file_path, records);

    cout << "Record updated successfully.\n";
}