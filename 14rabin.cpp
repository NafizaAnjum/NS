#include <iostream>
using namespace std;

// Modular exponentiation
int power(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Extended Euclidean Algorithm
int gcdExtended(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int main() {
    int p, q, m;

    cout << "Enter prime p (p%4=3): ";
    cin >> p;

    cout << "Enter prime q (q%4=3): ";
    cin >> q;

    cout << "Enter message: ";
    cin >> m;

    int n = p * q;

    // Encryption
    int c = (m * m) % n;

    cout << "\nEncrypted Message = " << c << endl;

    // Square roots
    int mp = power(c, (p + 1) / 4, p);
    int mq = power(c, (q + 1) / 4, q);

    // CRT
    int yp, yq;
    gcdExtended(p, q, yp, yq);

    int r1 = (yp * p * mq + yq * q * mp) % n;
    if (r1 < 0) r1 += n;

    int r2 = n - r1;

    int r3 = (yp * p * mq - yq * q * mp) % n;
    if (r3 < 0) r3 += n;

    int r4 = n - r3;

    cout << "\nPossible Decrypted Messages:\n";
    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;
    cout << r4 << endl;

    return 0;
}