#include <iostream>
using namespace std;

// Modular power function
int power(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        result = (result * base) % mod;
        exp--;
    }
    return result;
}

int main() {
    int p, q, e, d, message;

    cout << "Enter prime numbers (p q): ";
    cin >> p >> q;

    cout << "Enter public key (e): ";
    cin >> e;

    cout << "Enter private key (d): ";
    cin >> d;

    cout << "Enter message (number): ";
    cin >> message;

    int n = p * q;

    // Digital Signature
    int signature = power(message, d, n);
    cout << "Digital Signature: " << signature << endl;

    // Verification
    int verify = power(signature, e, n);

    if (verify == message)
        cout << "Signature Verified." << endl;
    else
        cout << "Signature Verification Failed." << endl;

    return 0;
}