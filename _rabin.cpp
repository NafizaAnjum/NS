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

int main()
{
    int p, q, M;

    cout << "Enter p: ";
    cin >> p;

    cout << "Enter q: ";
    cin >> q;

    cout << "Enter Plaintext: ";
    cin >> M;

    int n = p * q;

    // Encryption
    int C = (M * M) % n;

    cout << "\nPublic Key (n): " << n << endl;
    cout << "Ciphertext: " << C << endl;

    // Decryption (find all square roots)
    cout << "\nPossible Plaintexts:\n";

    for(int i = 0; i < n; i++)
    {
        if((i * i) % n == C)
            cout << i << " ";
    }

    cout << endl;

    return 0;
}