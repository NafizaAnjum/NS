#include <iostream>
using namespace std;

// Encryption
string encrypt(string text) {
    string row1 = "", row2 = "";

    for (int i = 0; i < text.length(); i++) {
        if (i % 2 == 0)
            row1 += text[i];
        else
            row2 += text[i];
    }

    return row1 + row2;
}

// Decryption
string decrypt(string cipher) {
    int mid = (cipher.length() + 1) / 2;
    string row1 = cipher.substr(0, mid);
    string row2 = cipher.substr(mid);

    string plain = "";
    int i = 0, j = 0;

    while (i < row1.length() || j < row2.length()) {
        if (i < row1.length())
            plain += row1[i++];
        if (j < row2.length())
            plain += row2[j++];
    }

    return plain;
}

int main() {
    string text;

    cout << "Enter Plain Text: ";
    cin >> text;

    string cipher = encrypt(text);
    cout << "Encrypted Text: " << cipher << endl;

    cout << "Decrypted Text: " << decrypt(cipher) << endl;

    return 0;
}