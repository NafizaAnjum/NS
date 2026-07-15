#include <iostream>
#include <string>
using namespace std;

int main() {
    string plain, cipher = "", decrypt = "";
    int key;

    cout << "Enter Plain Text (CAPITAL): ";
    cin >> plain;

    cout << "Enter Initial Numeric Key: ";
    cin >> key;

    int keystream[100];

    keystream[0] = key;
    for (int i = 1; i < plain.size(); i++)
        keystream[i] = plain[i - 1] - 'A';

    cout << "\nKeystream: ";
    for (int i = 0; i < plain.size(); i++)
        cout << keystream[i] << " ";

    // Encryption
    for (int i = 0; i < plain.size(); i++)
        cipher += char(((plain[i] - 'A' + keystream[i]) % 26) + 'A');

    cout << "\nCiphertext: " << cipher << endl;

    // Decryption
    decrypt += char(((cipher[0] - 'A' - key + 26) % 26) + 'A');

    for (int i = 1; i < cipher.size(); i++) {
        int k = decrypt[i - 1] - 'A';
        decrypt += char(((cipher[i] - 'A' - k + 26) % 26) + 'A');
    }

    cout << "Decrypted Text: " << decrypt << endl;

    return 0;
}