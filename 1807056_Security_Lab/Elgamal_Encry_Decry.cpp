#include<bits/stdc++.h>
using namespace std;
int big_mod(int base, int power, int mod)
{
    if(power==0)
    {
        return 1;
    }
    else if(power%2)
    {
        long long p=base%mod;
        long long q=big_mod(base,(power-1)/2,mod);
        return (p*q*q)%mod;
    }
    else
    {
        long long p=big_mod(base,(power)/2, mod);
        return(p*p)%mod;
    }
}


int modular_multiplicative_inverse(int a, int b)
{
    int t1=0;
    int t2=1;
    int t;
    int m=a;

    while(b)
    {
        int q=a/b;
        int r=a%b;
        a=b;
        b=r;
        t=t1-(q*t2);
        t1=t2;
        t2=t;
    }
    if(t1<0)
    {
        return t1+m;
    }
    return t1;
}

int main()
{   
    //take prime
    int p=13;
    //take primitve element g refers to alpha
    int g=2;
    //take private key a
    int a=3;
    //take random number k
    int k=5;
    
    //Compute beta
    int beta=big_mod(g,a,p);
    int msg = 56;


    // encryption 
    int y1=big_mod(g,k,p); // alpha^k mod p
    int y2= msg * big_mod(beta,k,p); //beta^k mod p 

    // decryption 
    int decryp_message = y2 / big_mod(y1, a, p); // 

    cout<<"Actual Message Is "<<msg<<endl;
    cout<<"Encrypted Message Is "<<y1<<" "<<y2<<endl;
    cout<<"Decrypted Message Is "<<decryp_message<<endl;

}