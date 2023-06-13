#include<bits/stdc++.h>
using namespace std;

//I assume all the key and plain text contains uppercase letter only
//Lower case letter can aslo be handled in similar fashion
int main()
{
    string plain_text="RAMSWARUPK";
    string key="RANCHOBABA ";

    string cipher_text="";
    string decrypt_text="";

    //Encryption
    for(int i=0; i<plain_text.size(); ++i)
    {
        int plain_int=plain_text[i]-65;
        int key_int=key[i]-65;
        int result=(plain_int^key_int);
        if(result>=26)
        {
            result=result-26;
        }
        char c=(65+result);
        cipher_text=cipher_text+c;
    }

    //Decryption
    for(int i=0; i<cipher_text.size(); ++i)
    {
        int cipher_int=cipher_text[i]-65;
        int key_int=key[i]-65;
        int result=(cipher_int^key_int);
        if(result>=26)
        {
            result=result-26;
        }
        char c=(65+result);
        decrypt_text=decrypt_text+c;
    }

    cout<<"Actual Text "<<plain_text<<endl;
    cout<<"Encrypted Text "<<cipher_text<<endl;
    cout<<"Decrypted_Text "<<decrypt_text<<endl;
}