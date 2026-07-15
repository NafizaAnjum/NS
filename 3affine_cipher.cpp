#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to find modular inverse of a under mod 26
int modInverse(int a) {
    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

// Affine Cipher (Encryption & Decryption)
string affine(string text, int a, int b, bool encrypt) {
    string result = "";
    int a_inv = modInverse(a);

    if (!encrypt && a_inv == -1) {
        cout << "Error: 'a' has no modular inverse.\n";
        return "";
    }

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';

            if (encrypt)
                result += char(((a * (c - base) + b) % 26) + base);
            else
                result += char((a_inv * ((c - base - b + 26) % 26)) % 26 + base);
        }
        else {
            result += c;   // Keep spaces and symbols
        }
    }

    return result;
}

int main() {
    string text;
    int a, b;

    cout << "Enter Text: ";
    getline(cin, text);

    cout << "Enter Multiplicative Key (a): ";
    cin >> a;

    cout << "Enter Additive Key (b): ";
    cin >> b;

    string cipher = affine(text, a, b, true);
    cout << "\nEncrypted Text: " << cipher << endl;

    string plain = affine(cipher, a, b, false);
    cout << "Decrypted Text: " << plain << endl;

    return 0;
}