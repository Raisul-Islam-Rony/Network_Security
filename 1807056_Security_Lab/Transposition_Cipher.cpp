#include<bits/stdc++.h>
using namespace std;

void print(char ara[][5])
{
    for (int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<ara[i][j]<<" ";
        }
        cout<<endl;
    }
}

int min_index(string key, bool visited[])
{
    int mini=INT_MAX;
    int index=-1;

    for(int i=0; i<key.size(); i++)
    {
        if(visited[i]==false)
        {
            if(key[i]<mini)
            {
                mini=key[i];
                index=i;
            }
        }
    }
    return index;


}
int main()
{
    string msg = "TRANSPOSITION";
    string key = "sithy";

    char msg_rep[5][5];
    int k=0, len=msg.size();

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(k<len)
            {
                msg_rep[i][j]=msg[k];
                k++;
            }
            else
            {
                msg_rep[i][j]='*';
            }
            
        }
    }
    k=0;
    
    bool visited[5];

    for(int i=0; i<5; i++)
    {
        visited[i]=false;
    }
    int sequence[5];
    for(int i=0; i<5; i++)
    {
        int x=min_index(key,visited);
        sequence[i]=x;
        visited[x]=true;
    }

    

    string encrypted_text="";
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5;j++)
        {
            encrypted_text+=msg_rep[j][sequence[i]];
        }
    }

    
    char cipher_rep[5][5];
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cipher_rep[i][j]=encrypted_text[k];
            k++;
        }
    }
    print(msg_rep);
    cout<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<sequence[i]<<" ";
    }
    cout<<endl;

    
    print(cipher_rep);
    cout<<encrypted_text<<endl;

    char decryp_rep[5][5];
    
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            decryp_rep[j][sequence[i]]=cipher_rep[i][j];
        }
    }
    
    print(decryp_rep);
    
}