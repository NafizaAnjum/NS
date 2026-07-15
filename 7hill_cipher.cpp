#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int modInverse(int a) {
    a = (a % 26 + 26) % 26;
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1)
            return i;
    return -1;
}

string encrypt(string text, int key[2][2]) {
    if (text.length() % 2) text += 'X';

    string cipher = "";

    for (int i = 0; i < text.length(); i += 2) {
        int p1 = toupper(text[i]) - 'A';
        int p2 = toupper(text[i + 1]) - 'A';

        cipher += char((key[0][0] * p1 + key[0][1] * p2) % 26 + 'A');
        cipher += char((key[1][0] * p1 + key[1][1] * p2) % 26 + 'A');
    }

    return cipher;
}

string decrypt(string cipher, int key[2][2]) {
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
    if (det < 0) det += 26;

    int invDet = modInverse(det);
    if (invDet == -1) return "Invalid Key";

    int inv[2][2];

    inv[0][0] = ( key[1][1] * invDet) % 26;
    inv[0][1] = (-key[0][1] * invDet + 26) % 26;
    inv[1][0] = (-key[1][0] * invDet + 26) % 26;
    inv[1][1] = ( key[0][0] * invDet) % 26;

    string plain = "";

    for (int i = 0; i < cipher.length(); i += 2) {
        int c1 = cipher[i] - 'A';
        int c2 = cipher[i + 1] - 'A';

        plain += char((inv[0][0] * c1 + inv[0][1] * c2) % 26 + 'A');
        plain += char((inv[1][0] * c1 + inv[1][1] * c2) % 26 + 'A');
    }

    return plain;
}

int main() {
    string text;
    int key[2][2];

    cout << "Enter Plain Text: ";
    cin >> text;

    cout << "Enter 2x2 Key Matrix:\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> key[i][j];

    // Check if key matrix is valid
    int det = key[0][0] * key[1][1] - key[0][1] * key[1][0];
    det = (det % 26 + 26) % 26;

    if (modInverse(det) == -1) {
        cout << "Invalid Key Matrix! Determinant has no modular inverse." << endl;
        return 0;
    }

    string cipher = encrypt(text, key);

    cout << "Encrypted Text: " << cipher << endl;
    cout << "Decrypted Text: " << decrypt(cipher, key) << endl;

    return 0;
}