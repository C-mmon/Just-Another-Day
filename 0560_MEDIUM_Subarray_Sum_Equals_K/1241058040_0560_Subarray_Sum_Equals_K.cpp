class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //we have to find the total sub-array 
        //Take an Example [3,4,7,-2,2,1,4,2] and k=7
        // Solution is 4
        // we have [3+4], [7], [7,-2,2], [-2,2,1,4,2] [2,1,4], [1,4,2]
        // two pointer approach misses on the cases 

        // we need to store sum frequencies in hash table
        // sum (i,j) is sum(0,j)-sum(0,i)
        int n = nums.size();
        unordered_map <int,int> mp; 
        int prefix[n];
        prefix[0]= nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]= prefix[i-1]+nums[i];
        }
        int ans =0;
        for(int i=0;i<n; i++)
        {
            if(prefix[i] == k)
            {
                ans++;
            }
            // find whether prefix[i] -k presents in map
            if(mp.find(prefix[i]-k) != mp.end())
            {
                ans+=mp[prefix[i]-k];
            }
            mp[prefix[i]]++; // put prefix sum into our map
        }

        return ans;


    }
};