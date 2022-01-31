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
     
     ll area(ll a, ll b, ll x, ll y)
     {
    ll top, left, bottom, right, res1, res2, res;
    bottom = a*(b-(y+1));
    top = a*b-(bottom+a);
    left = b*x;
    right = a*b-(left+b);
    res1 = std::max(top, bottom);
    res2 = std::max(left, right);
    res = std::max(res1, res2);
    return res; 
    }

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
   

    void solve()
    {
         ll n;
         ll num;
         cin>>k;
         for(ll i=0;i<k; i++)
         {
            cin>>num;
            b.push_back(num);
         }  

         for(ll i=0; i<k; i++)
         {
            cin>>num;
            c.push_back(num);
         }
         cin>>n;
         cout<<compute(n)<<endl;
         b.clear();
         c.clear();
         
        
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
         cin>>t;
        for(int i=1;i<=t;i++)
                    
           solve();
      
        return 0;
    }
