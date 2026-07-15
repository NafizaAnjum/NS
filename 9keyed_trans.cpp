#include <iostream>
using namespace std;

int main() {
    string text, cipher = "", plain = "";
    int col;

    cout << "Enter Plain Text: ";
    cin >> text;

    cout << "Enter Number of Columns: ";
    cin >> col;

    int key[col];
    cout << "Enter Key Order: ";
    for (int i = 0; i < col; i++)
        cin >> key[i];

    while (text.length() % col != 0)
        text += 'X';

    int row = text.length() / col;
    char mat[row][col];

    // Fill matrix row-wise
    int k = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat[i][j] = text[k++];

    // Encryption
    for (int x = 0; x < col; x++) {
        int c = key[x] - 1;      // Convert to 0-based index
        for (int i = 0; i < row; i++)
            cipher += mat[i][c];
    }

    cout << "Encrypted Text: " << cipher << endl;

    // Decryption
    char mat2[row][col];
    k = 0;

    for (int x = 0; x < col; x++) {
        int c = key[x] - 1;
        for (int i = 0; i < row; i++)
            mat2[i][c] = cipher[k++];
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            plain += mat2[i][j];

    while (!plain.empty() && plain.back() == 'X')
        plain.pop_back();

    cout << "Decrypted Text: " << plain << endl;

    return 0;
}