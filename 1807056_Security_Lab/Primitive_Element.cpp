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

// If traverse start from 1 then traverse upto p-1
bool Primitve_Element(int p, int g)
{
    vector<int> vect(p, 0);
    for(int i=0; i<p-1; i++)
    {
        int x=big_mod(g,i,p);
        if(vect[x]>0)
        {
            return false;
        }
        vect[x]++;
    }
    return true;

}
int main()
{
    int p=13;
    int g;
    for(int i=1; i<p; i++)
    {
        if(Primitve_Element(p,i))
        {
            g=i;
            break;
        }
    }

    cout<<"Primitve Element Is "<<g<<endl;
}