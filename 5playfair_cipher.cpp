#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char key[5][5];

void createKey(string k) {
    bool used[26] = {0};
    used['J' - 'A'] = true;
    string s = "";

    for (char c : k) {
        c = toupper(c);
        if (c == 'J') c = 'I';
        if (isalpha(c) && !used[c - 'A']) {
            used[c - 'A'] = true;
            s += c;
        }
    }

    for (char c = 'A'; c <= 'Z'; c++)
        if (!used[c - 'A']) s += c;

    int x = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            key[i][j] = s[x++];
}

void findPos(char c, int &r, int &col) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (key[i][j] == c) {
                r = i;
                col = j;
            }
}

string prepare(string s) {
    string t = "";
    for (char c : s)
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            t += c;
        }

    string p = "";
    for (int i = 0; i < t.length(); i++) {
        p += t[i];
        if (i + 1 < t.length() && t[i] == t[i + 1])
            p += 'X';
    }
    if (p.length() % 2) p += 'X';
    return p;
}

string encrypt(string s) {
    string c = "";
    for (int i = 0; i < s.length(); i += 2) {
        int r1, c1, r2, c2;
        findPos(s[i], r1, c1);
        findPos(s[i + 1], r2, c2);

        if (r1 == r2) {
            c += key[r1][(c1 + 1) % 5];
            c += key[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            c += key[(r1 + 1) % 5][c1];
            c += key[(r2 + 1) % 5][c2];
        } else {
            c += key[r1][c2];
            c += key[r2][c1];
        }
    }
    return c;
}

string decrypt(string s) {
    string p = "";
    for (int i = 0; i < s.length(); i += 2) {
        int r1, c1, r2, c2;
        findPos(s[i], r1, c1);
        findPos(s[i + 1], r2, c2);

        if (r1 == r2) {
            p += key[r1][(c1 + 4) % 5];
            p += key[r2][(c2 + 4) % 5];
        } else if (c1 == c2) {
            p += key[(r1 + 4) % 5][c1];
            p += key[(r2 + 4) % 5][c2];
        } else {
            p += key[r1][c2];
            p += key[r2][c1];
        }
    }
    return p;
}

int main() {
    string keyWord, text;

    cout << "Enter Key: ";
    getline(cin, keyWord);

    cout << "Enter Plain Text: ";
    getline(cin, text);

    createKey(keyWord);

    string p = prepare(text);
    string cipher = encrypt(p);

    cout << "Encrypted: " << cipher << endl;
    cout << "Decrypted: " << decrypt(cipher) << endl;

    return 0;
}