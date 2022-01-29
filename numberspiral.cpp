    #include <iostream>
    #include <bits/stdc++.h>
    #include<stdio.h> 
    #include<string.h>
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
     int flag=0;
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


   

    void solve()
    {
            ll x;
            ll y;
            cin>>x>>y;
            if(x<y)
                {
                    if(y%2!=0)
                        cout<<(y*y)-x+1<<endl;
                    else
                        cout<<((y-1)*(y-1))+x<<endl;
                }
            else
                {
                    if(x%2!=0)
                        cout<<((x-1)*(x-1)+y)<<endl;
                    else
                        cout<<(x*x)-y+1<<endl;

                }

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
