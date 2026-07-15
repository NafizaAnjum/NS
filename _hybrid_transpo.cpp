#include <iostream>
#include <vector>
using namespace std;

// Rail Fence Encryption (2 rails)
string railEncrypt(string text)
{
    string r1="", r2="";
    for(int i=0;i<text.length();i++)
    {
        if(i%2==0) r1+=text[i];
        else r2+=text[i];
    }
    return r1+r2;
}

// Rail Fence Decryption (2 rails)
string railDecrypt(string text)
{
    int mid=(text.length()+1)/2;
    string r1=text.substr(0,mid);
    string r2=text.substr(mid);

    string ans="";
    int i=0,j=0;

    while(i<r1.length() || j<r2.length())
    {
        if(i<r1.length()) ans+=r1[i++];
        if(j<r2.length()) ans+=r2[j++];
    }

    return ans;
}

// Columnar Encryption
string columnEncrypt(string text,int key[])
{
    while(text.length()%4!=0)
        text+='X';

    int rows=text.length()/4;
    char mat[20][4];

    int k=0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<4;j++)
            mat[i][j]=text[k++];

    string ans="";

    for(int n=1;n<=4;n++)
        for(int c=0;c<4;c++)
            if(key[c]==n)
                for(int r=0;r<rows;r++)
                    ans+=mat[r][c];

    return ans;
}

// Columnar Decryption
string columnDecrypt(string text,int key[])
{
    int rows=text.length()/4;
    char mat[20][4];

    int k=0;

    for(int n=1;n<=4;n++)
        for(int c=0;c<4;c++)
            if(key[c]==n)
                for(int r=0;r<rows;r++)
                    mat[r][c]=text[k++];

    string ans="";

    for(int i=0;i<rows;i++)
        for(int j=0;j<4;j++)
            ans+=mat[i][j];

    return ans;
}

int main()
{
    string plain;
    int key[4];
    int rails;

    cout<<"Plaintext: ";
    cin>>plain;

    cout<<"Step 1 Rails: ";
    cin>>rails;      // use 2

    cout<<"Step 2 Key: ";
    for(int i=0;i<4;i++)
        cin>>key[i];

    string inter=railEncrypt(plain);
    string cipher=columnEncrypt(inter,key);

    string temp=columnDecrypt(cipher,key);
    string original=railDecrypt(temp);

    cout<<"\nIntermediate Text: "<<inter;
    cout<<"\nFinal Ciphertext: "<<cipher;
    cout<<"\nDecrypted Text: "<<original;

    return 0;
}