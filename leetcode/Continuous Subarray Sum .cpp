class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k3) {
       int k=abs(k3);
       if(k==0)
        {
            for(int i=1;i<nums.size();i++)
            {
                if(nums[i]+nums[i-1]==0)return true;
            }
            return false;
        }
for(int i=0;i<nums.size();i++)
	{
	int s=0;
	for(int j=i;j<nums.size();j++)
		{
		s+=nums[j];
		if(s%k==0 && j-i>=1)return true;
		}
	}
return false; 
    }
};
