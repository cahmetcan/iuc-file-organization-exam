#ifndef RECORD_MANAGER_H
#define RECORD_MANAGER_H

#include <string>
#include <vector>
#include <map>

struct Record { // bir records' type
    int id;
    std::string name;
    std::string departmant;
};

std::vector<Record> read_records(const std::string &file_path);
void insert_record(std::vector<Record> &records, const Record &new_record);
void write_records(const std::string &file_path,
                   const std::vector<Record> &records);
void createUser(const std::string &file_path);
void deleteUser(const std::string &file_path);
void updateUser(const std::string &file_path);

std::string getLineFromFile(const std::string &filename, int lineNumber);
void directAccess(const std::string &filename, int position, int size);

void searchByKey(const std::string &filename, const std::map<std::string, long> &index,
                 const std::string &key);
std::map<std::string, long> buildIndex(const std::string &filename);

void searchByKey(const std::string &filename, const std::map<std::string, long> &index,
                 const std::string &key);

#endif // RECORD_MANAGER_H
