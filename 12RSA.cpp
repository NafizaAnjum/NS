#include <iostream>
#include <cmath>
using namespace std;

int power(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        result = (result * base) % mod;
        exp--;
    }
    return result;
}

int main() {
    int p, q, e, m;

    cout << "Enter two prime numbers (p q): ";
    cin >> p >> q;

    cout << "Enter public key (e): ";
    cin >> e;

    cout << "Enter message (number): ";
    cin >> m;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Find private key d
    int d;
    for (d = 1; d < phi; d++)
        if ((d * e) % phi == 1)
            break;

    // Encryption
    int c = power(m, e, n);

    // Decryption
    int plain = power(c, d, n);

    cout << "\nPublic Key (e,n): (" << e << "," << n << ")" << endl;
    cout << "Private Key (d,n): (" << d << "," << n << ")" << endl;
    cout << "Encrypted Message: " << c << endl;
    cout << "Decrypted Message: " << plain << endl;

    return 0;
}