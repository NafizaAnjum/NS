#include <iostream>
using namespace std;

// Modular exponentiation
int modPow(int base, int exp, int mod)
{
    int result = 1;
    while(exp > 0)
    {
        result = (result * base) % mod;
        exp--;
    }
    return result;
}

// Modular inverse
int modInverse(int a, int m)
{
    a = a % m;
    for(int i = 1; i < m; i++)
        if((a * i) % m == 1)
            return i;
    return -1;
}

int main()
{
    int p, q, g, x, h, k;

    cout << "Enter p q g: ";
    cin >> p >> q >> g;

    cout << "Enter private key x: ";
    cin >> x;

    cout << "Enter message hash H(m): ";
    cin >> h;

    cout << "Enter random k: ";
    cin >> k;

    // Public key
    int y = modPow(g, x, p);

    // Signature
    int r = modPow(g, k, p) % q;
    int kinv = modInverse(k, q);
    int s = (kinv * (h + x * r)) % q;

    cout << "\nPublic Key y = " << y << endl;
    cout << "Signature (r,s) = (" << r << "," << s << ")" << endl;

    // Verification
    int w = modInverse(s, q);
    int u1 = (h * w) % q;
    int u2 = (r * w) % q;

    int v = ((modPow(g, u1, p) * modPow(y, u2, p)) % p) % q;

    if(v == r)
        cout << "Signature Valid";
    else
        cout << "Signature Invalid";

    return 0;
}