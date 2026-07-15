#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Additive Cipher (Encryption & Decryption)
string additive(string text, int key, bool encrypt) {
    string result = "";

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';

            if (encrypt)
                result += char((c - base + key) % 26 + base);
            else
                result += char((c - base - key + 26) % 26 + base);
        }
        else {
            result += c;   // Keep spaces and symbols
        }
    }

    return result;
}

int main() {
    string text;
    int key;

    cout << "Enter Text: ";
    getline(cin, text);

    cout << "Enter Key: ";
    cin >> key;

    key %= 26;   // Keep key within 0-25

    string cipher = additive(text, key, true);
    cout << "\nEncrypted Text: " << cipher << endl;

    string plain = additive(cipher, key, false);
    cout << "Decrypted Text: " << plain << endl;

    return 0;
}