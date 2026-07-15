#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string vigenere(string text, string key, bool encrypt) {
    string result = "";
    int j = 0;

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = toupper(key[j % key.length()]) - 'A';

            if (encrypt)
                result += char((c - base + k) % 26 + base);
            else
                result += char((c - base - k + 26) % 26 + base);

            j++;
        }
        else {
            result += c;   // Keep spaces and symbols
        }
    }

    return result;
}

int main() {
    string text, key;

    cout << "Enter Plain Text: ";
    getline(cin, text);

    cout << "Enter Key: ";
    cin >> key;

    string cipher = vigenere(text, key, true);
    cout << "\nEncrypted Text: " << cipher << endl;

    string plain = vigenere(cipher, key, false);
    cout << "Decrypted Text: " << plain << endl;

    return 0;
}