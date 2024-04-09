    if(arr.size()<3)
        {
            return 0;
        }
       bool increasing=false;
       int ans=0;
       int length=0;
       for(int i=0;i<arr.size()-1;i++)
       {
        if(arr[i] <=arr[i+1] && increasing == false && length !=0)
        {
            ans= max(ans, length);
            length = 0;
            increasing = true;
        }
        if(arr[i] <arr[i+1])
        {
            length++;
            increasing = true;
        }
        else if(length != 0 && arr[i] >arr[i+1])
        {
            length++;
            increasing=false;
        }
        if(arr[i] == arr[i+1])
        {
            length=0;
            increasing = false;
        }
       }
       if (length != 0 && increasing == false) {
        ans = max(ans, length); // Update 'ans' for the last sequence
    }
       if(ans == 0)
       {
        return 0;
       }
       else
       {
        return ans+1;
       }
