   int getMinDiff(int a[], int n, int k) 
   {
        
        sort(a,a+n);
        int i;
        int small=a[0]+k;
        int big=a[n-1]-k;
        if(small>big)
        swap(small,big);
        for(i=1; i<n-1; i++)
        {
            int sub=a[i]-k;
            int add=a[i]+k;
            if(sub>=small||add<=big)
            continue;
            else if(big-sub<=add-small)
            small=sub;
            else
            big=add;
        }
     return min(big-small,a[n-1]-a[0]);
