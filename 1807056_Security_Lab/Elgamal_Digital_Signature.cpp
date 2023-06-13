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
    //Prime
    int p=13;
    //Primitve
    int g=2;

    //Private 
    int a=3;
    //Random
    int k=5;

    //Compute Beta
    int beta=big_mod(g,a,p);

    int msg=2;

    ///Signature

    int y1=big_mod(g,k,p);
    int y2=((msg-a*y1)*modular_multiplicative_inverse(p-1,k))%(p-1);
    if(y2<0)
    {
       y2= (y2 + (p-1))%(p-1);
    }

    //Verify
    int l_h_s=big_mod(g,msg,p);
    int r_h_s=((big_mod(y1,y2,p))*(big_mod(beta,y1,p)))%p;

   

    if(l_h_s==r_h_s)
    {   cout<<"Siganture "<<l_h_s<<endl;
        cout<<"Verification "<<r_h_s<<endl;
        cout<<"Siganture Is Matched "<<endl;
    }

    else
    {
        cout<<"Digital Signature Failed"<<endl;
    }

}