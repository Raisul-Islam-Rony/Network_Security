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

int gcd(int a, int b)
{
    while(b)
    {
        int p=a%b;
        a=b;
        b=p;
    }
    return a;
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
    //first take two prime
    int p=313;
    int q=769;
    //compute n

    int n =p*q;
    //compute phi

    int phi=(p-1)*(q-1);

    //Compute public key, e

    int e=p;

    /// 1<e<phi, gcd(e,phi)==1
    while(e<phi)
    {
        if(gcd(phi,e)==1)
        {
            break;
        }
        e+=1;
    }
    
    ///compute private key d, (e*d)mod phi=1
    int d=modular_multiplicative_inverse(phi,e);

    int msg=56;

    ///encrypt_msg=(m^e)mod n
    int encryp_msg=big_mod(msg,e,n);
    
    ///decrypt_msg=(encrypt_msg^d)mod n
    int decryp_msg=big_mod(encryp_msg,d,n);

    cout<<"Message is "<<msg<<endl;
    cout<<"Encrypted Message is "<<encryp_msg<<endl;
    cout<<"Decrypted Message is "<<decryp_msg<<endl;


}