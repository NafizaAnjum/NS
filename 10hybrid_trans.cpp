#include <iostream>
using namespace std;

// ---------- Keyless Encryption ----------
string keylessEncrypt(string text) {
    string row1 = "", row2 = "";

    for (int i = 0; i < text.length(); i++) {
        if (i % 2 == 0)
            row1 += text[i];
        else
            row2 += text[i];
    }

    return row1 + row2;
}

// ---------- Keyless Decryption ----------
string keylessDecrypt(string cipher) {
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

// ---------- Keyed Encryption ----------
string keyedEncrypt(string text, int key[], int col) {

    while (text.length() % col != 0)
        text += 'X';

    int row = text.length() / col;
    char mat[row][col];

    int k = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat[i][j] = text[k++];

    string cipher = "";

    for (int x = 0; x < col; x++) {
        int c = key[x] - 1;

        for (int i = 0; i < row; i++)
            cipher += mat[i][c];
    }

    return cipher;
}

// ---------- Keyed Decryption ----------
string keyedDecrypt(string cipher, int key[], int col) {

    int row = cipher.length() / col;
    char mat[row][col];

    int k = 0;

    for (int x = 0; x < col; x++) {
        int c = key[x] - 1;

        for (int i = 0; i < row; i++)
            mat[i][c] = cipher[k++];
    }

    string plain = "";

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            plain += mat[i][j];

    while (!plain.empty() && plain.back() == 'X')
        plain.pop_back();

    return plain;
}

int main() {

    string text;
    int col;

    cout << "Enter Plain Text: ";
    cin >> text;

    cout << "Enter Number of Columns: ";
    cin >> col;

    int key[col];

    cout << "Enter Key Order: ";
    for (int i = 0; i < col; i++)
        cin >> key[i];

    // Hybrid Encryption
    string step1 = keylessEncrypt(text);
    string cipher = keyedEncrypt(step1, key, col);

    cout << "\nEncrypted Text: " << cipher << endl;

    // Hybrid Decryption
    string step2 = keyedDecrypt(cipher, key, col);
    string plain = keylessDecrypt(step2);

    cout << "Decrypted Text: " << plain << endl;

    return 0;
}