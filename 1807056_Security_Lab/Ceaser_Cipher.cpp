#include<bits/stdc++.h>
using namespace std;

//Assuming message is of capital
int main()
{
    string plain_text="RONY";
    int shift=4;

    string encrypted_text="";

    //Encryption
    for(int i=0; i<plain_text.size(); i++)
    {
        char c=plain_text[i];
        if((c+4)>90)
        {

            int x= c+4;
            x=(x-90);
            c=65+x-1;
        }
        else
        {
            c+=4;
        }
        encrypted_text+=c;

    }

    cout<<encrypted_text<<endl;


    //Decryption

    string decryption_text="";
        for(int i=0; i<encrypted_text.size(); i++)
    {
        char c=encrypted_text[i];
        if(c-4<65)
        {
            int x=c-4;
            x=65-x;
            c=90-x+1;

        }
        else
        {
            c=c-4;
        }

        decryption_text+=c;
    }

    cout<<decryption_text<<endl;



}