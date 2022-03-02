    #include <iostream>
    #include <bits/stdc++.h>
    #include<stdio.h> 
    #include<string.h>

    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
   #define ll long long int
   #define pb push_back
   #define cl CLOCKS_PER_SEC
   #define pi acos(-1.0)
   #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
   #define flw freopen ("/Desktop/misc/output.txt","w",stdout);
   #define flr freopen ("/Desktop/misc/input.txt","r",stdin);
   #define fl freopen ("output.txt","w",stdout);freopen ("input.txt","r",stdin)

   #define no1s(x) __builtin_popcount(x)
   #define parity(x) __builtin_parity(x)
   #define leadingZeros(x) __builtin_clz(x)
   #define trailingZeros(x) __builtin_ctz(x)
   #define mod 1000000007
     using namespace std;
     using namespace __gnu_pbds;


      ll gcd(ll a, ll b)
      {
        if(b==0)
          return a;
        return gcd(b,a%b);
      }
     ll isPrime(ll n)
     {
         ll flag=1;
       for(ll i=2; i<n; i++)
        {if(n%i==0)
          flag=0;}

        return flag;


     }
     float newPrecision(float n, float i)
{
    return floor(pow(10,i)*n)/pow(10,i);
}
char upper(char s)
{
  return (s+'a'-'A');
}
void inputarray(ll A[], ll n)
{


  for(ll i=0; i<n; i++)
    cin>>A[i];
}
ll fastmodexp(ll a, ll b, ll n)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b=b>>1;
    }
    return res;
}

ll power_optimised(ll a, ll n)
{
   ll ans=1;
   while(n>0)
   {
      int last_bit=(n&1);
      if(last_bit)
        ans*=a;
      a=a*a;
      n=n>>1;

   }
   return ans;


}
 ll isOrdinary(ll n)
{
    
    ll arr[10];
    for (int i=0; i<10; i++)
        arr[i] = 0;
 
    while (n > 0)
    {
         int digit = n%10;
 
         if (arr[digit])
           return 0;
 
         arr[digit] = 1;
 
         n = n/10;
    }
    return 1;
}

  vector<ll> a,b,c;
     ll k;
     
     vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B)
     {

        vector<vector<ll>> C(k+1,vector<ll>(k+1));
        for(ll i=1; i<=k; i++)
            for(ll j=1; j<=k; j++)
                for(ll x=1; x<=k; x++)
                    C[i][j]=((C[i][j]+(A[i][x]*B[x][j])%mod)%mod);
        return C;
     }

     vector<vector<ll>> pow(vector<vector<ll>> A,ll p)
     {
        if(p==1) 
            return A;
        if(p&1)
            return multiply(A,pow(A,p-1));
        else
        {
            vector<vector<ll>> x=pow(A,p/2);
            return multiply(x,x);
        }
     }

     ll compute(ll n)
     {
        if(n==0)
            return 0;
        if(n<=k)
            return b[n-1];
       
        vector<ll> F1(k+1);
        
        for(ll i=1; i<=k; i++)
            F1[i]=b[i-1];
        
        vector<vector<ll>> T(k+1, vector<ll>(k+1));
        for(ll i=1; i<=k; i++)
        {
            for(ll j=1; j<=k; j++)
            {
                if(i<k)
                {
                    if(j==i+1)
                        T[i][j]=1;
                    else
                        T[i][j]=0;
                }
                else
                    T[i][j]=c[k-j];
            }
        }
        T=pow(T,n-1);
        ll res=0;
        for(ll i=1; i<=k; i++)
        {
            res=(res+(T[1][i]*F1[i])%mod)%mod;
        }
        return res;


     }
 bitset<10000000> bs; 
void sieve() 

{
    bs[0] = bs[1] = true;
    for (ll i = 2; i <= 1e7; i++) 
    {
        if (!bs[i])
            for (ll j = i * 1ll * i; j <= 1e7; j += i)
                bs[j] = true;
    }
}


void extendedEuclidMethod(ll a, ll b)
{
 ll x;
 ll y;
 ll GCD;
    if(b==0)
    {
        x=1;
        y=0;
        GCD=a;
    }
    extendedEuclidMethod(b,a%b);
    ll cX=y;
    ll cY=x-(a/b)*y;
    x=cX;
    y=cY;
}
   
ll modInverse(ll a, ll m)
{
    if(m==1)
        return 0;
    ll m0=m, y=0, x=1;

    while(a>1)
    {
        ll q=a/m,t=m;
        m=a%m, a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0)
        x+=m0;
    return x;
}

ll power(ll x, ll y)
{
    ll temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);       
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}  


ll getMedian(ll ar1[], ll ar2[], ll n, ll m) 
{ 
    ll i = 0;  
    ll j = 0; 
    ll count; 
    ll m1 = -1, m2 = -1; 
    if((m + n) % 2 == 1) 
    {
        for (count = 0; count <= (n + m)/2; count++) 
        {
            if(i != n && j != m)
            m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            
            else if(i < n)
            m1 = ar1[i++];
            
            else
            m1 = ar2[j++];
            
        }
        return m1;
    }
      
    else 
    {
        for (count = 0; count <= (n + m)/2; count++) 
        {
            
            m2 = m1;
            if(i != n && j != m)
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            else
             
             if(i < n)
                    m1 = ar1[i++];
             else
                    m1 = ar1[j++];
            
        }
        return (m1 + m2)/2;
    }
}


    void solve()
    {
        string s;
        string t;
        cin>>s>>t;
        bool ok=false;
        if(s==t)
            ok=true;
        for(ll i=0; i<s.length()-1; i++)
        {
            swap(s[i],s[i+1]);
            if(s==t)
                ok=true;
            swap(s[i],s[i+1]);
        }
        if(ok)
            cout<<"Yes";
        else
            cout<<"No";








    }
    


    




    
 int main()
    {
        ios::sync_with_stdio(0);
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cout<<fixed;
        cout<<setprecision(10);
        #ifndef ONLINE_JUDGE
        fl;
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";   
    #endif

      ll t=1;
    //  cin>>t;
        sieve();
        for(int i=1;i<=t;i++)
                    
           solve();
      
        return 0;
    }
