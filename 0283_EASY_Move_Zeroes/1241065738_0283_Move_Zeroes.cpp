class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int count =0;
     int snowballSize =0;
     for(int i=0;i<nums.size();i++)
     {
        if(nums[i] == 0)
        {
            snowballSize++;
        }else if(snowballSize > 0)
        {
            int temp= nums[i];
            nums[i] =0;
            nums[i-snowballSize]= temp;
        }
     }   
    }
};