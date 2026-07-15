#include <iostream>
#include <vector>
using namespace std;

// Round Function
int F(int right, int key) {
    return right ^ key;
}

int main() {
    int L, R, rounds;

    cout << "Enter Left Half: ";
    cin >> L;

    cout << "Enter Right Half: ";
    cin >> R;

    cout << "Enter Number of Rounds: ";
    cin >> rounds;

    vector<int> keys(rounds);

    for (int i = 0; i < rounds; i++) {
        cout << "Enter Key " << i + 1 << ": ";
        cin >> keys[i];
    }

    // Save original values
    int originalL = L;
    int originalR = R;

    // ---------------- Encryption ----------------
    cout << "\n----- Encryption -----\n";

    for (int i = 0; i < rounds; i++) {
        int temp = R;
        R = L ^ F(R, keys[i]);
        L = temp;

        cout << "Round " << i + 1
             << " -> L = " << L
             << ", R = " << R << endl;
    }

    cout << "\nEncrypted Block: (" << L << ", " << R << ")\n";

    // Save ct
    int cipherL = L;
    int cipherR = R;

    // ---------------- Decryption ----------------
    cout << "\n----- Decryption -----\n";

    L = cipherL;
    R = cipherR;

    for (int i = rounds - 1; i >= 0; i--) {
        int temp = L;
        L = R ^ F(L, keys[i]);
        R = temp;

        cout << "Round " << (rounds - i)
             << " -> L = " << L
             << ", R = " << R << endl;
    }

    cout << "\nDecrypted Block: (" << L << ", " << R << ")\n";

    if (L == originalL && R == originalR)
        cout << "\nDecryption Successful!\n";
    else
        cout << "\nDecryption Failed!\n";

    return 0;
}