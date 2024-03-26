#include "funcs.h"
#include <iostream>
using namespace std;

int main() {
    const string file_path = "records.txt";

    string input;
    while (true) {
        cout << "Enter a function to use: ";
        cout << "createUser, getLineFromFile, directAccess, searchByKey"
             << endl;
        cin >> input;

        if (input == "createUser") {
            /*
            bu fonksiyon kullanıcıdan id, name ve departman bilgilerini alıyor
            ve bu bilgileri records.txt dosyasına ekliyor
            eklerken numarasına göre sıralı ekliyor
            yani numarası küçük olandan büyüğe doğru ekliyor
             */
            createUser(file_path);
        } else if (input == "getLineFromFile") {
            /*
            bu fonksiyon kullanıcıdan bir satır numarası alıyor
            ve bu satır numarasındaki satırı ekrana yazdırıyor
             */
            int lineNumber;
            cout << "Enter line number: ";
            cin >> lineNumber;
            cout << getLineFromFile(file_path, lineNumber) << endl;
        } else if (input == "directAccess") {
            /*
            bu fonksiyon kullanıcıdan bir pozisyon alıyor
            ve bu pozisyondaki satırı ekrana yazdırıyor
             */
            int position;
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter size: ";
            int size;
            cin >> size;
            directAccess(file_path, position, size);
        } else if (input == "searchByKey") {
            /*
            bu anahtara göre records.txt dosyasında arama yapıyor
            bu aramayı index dosyası üzerinden yapıyor
            ilk olarak index dosyası oluşturuluyor
             */
            auto index = buildIndex(file_path);
            string key;
            cout << "Enter key: ";
            cin >> key;
            searchByKey(file_path, index, key);
        } else if (input == "deleteUser") {
            deleteUser(file_path);
        } else if (input == "updateUser") {
            updateUser(file_path);
        }

        else {
            cout << "Invalid function." << endl;
        }
    }

    return 0;
}
