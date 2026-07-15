#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

long long modInverse(long long t, long long m)
{
    for(int i = 1; i < m; i++)
        if((t * i) % m == 1)
            return i;
    return -1;
}

int main()
{
    vector<long long> W = {2,3,7,14,30,57,120,251};
    long long m = 491, t = 41;

    cout << "Private Key: ";
    for(auto x : W) cout << x << " ";
    cout << "\nm = " << m << "\nt = " << t << endl;

    vector<long long> B;
    cout << "\nPublic Key: ";
    for(auto x : W)
    {
        B.push_back((x * t) % m);
        cout << B.back() << " ";
    }

    string msg;
    cout << "\n\nEnter Message: ";
    getline(cin, msg);

    vector<long long> cipher;

    cout << "\nEncrypted Values:\n";
    for(char ch : msg)
    {
        bitset<8> bits((unsigned char)ch);
        long long sum = 0;

        for(int i = 0; i < 8; i++)
            if(bits[7 - i])
                sum += B[i];

        cipher.push_back(sum);
        cout << sum << " ";
    }

    long long inv = modInverse(t, m);
    string plain = "";

    for(long long c : cipher)
    {
        long long x = (c * inv) % m;
        string bits = "00000000";

        for(int i = 7; i >= 0; i--)
        {
            if(x >= W[i])
            {
                bits[i] = '1';
                x -= W[i];
            }
        }

        plain += char(bitset<8>(bits).to_ulong());
    }

    cout << "\n\nDecrypted Message: " << plain << endl;
}