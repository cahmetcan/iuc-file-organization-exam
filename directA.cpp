#include <fstream>
#include <iostream>

using namespace std;

// Dosyadan belirtilen pozisyondan itibaren veri okuyan directAccess fonksiyonu
void directAccess(const string &filename, int position, int size) {
    ifstream file(filename,
                  ios::binary); // bu şekilde dosya binary olarak açılır ve data
                                // eklenirken bozulma olmaz
    if (!file) {
        cerr << "Dosya açılamadı: " << filename << endl;
        return;
    }

    file.seekg(
        position); // Dosyanın okuma pozisyonunu belirtilen pozisyona getirir.

    char buffer[size];
    file.read(
        buffer,
        sizeof(
            buffer)); // Dosyadan belirtilen pozisyondan itibaren veriyi okur.

    cout << "Okunan veri: " << buffer << endl;

    file.close();
}

// istersek satır numarasına göre de okuma yapabiliriz
string getLineFromFile(const string &filename, int lineNumber) {
    ifstream file(filename);
    string line;
    int currentLine = 0;

    while (getline(file, line)) {
        currentLine++;
        if (currentLine == lineNumber) {
            file.close();
            return line;
        }
    }

    file.close();
    return "Not found";
}