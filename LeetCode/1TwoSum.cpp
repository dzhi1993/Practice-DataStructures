#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{	
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		vector<int> index;
		map<int, vector<int>::size_type> indexMap;
		
		for (vector<int>::size_type i = 0; i < nums.size(); i++)
		{
			if (indexMap.find(nums[i]) == indexMap.end())
			{
				indexMap.insert(std::pair<int, vector<int>::size_type>(nums[i], i));
			}
			if ((indexMap.find(target - nums[i]) != indexMap.end()) && (indexMap.find(target - nums[i])->second != i))
			{
				index.push_back(indexMap.find(target - nums[i])->second);
				index.push_back(i);
				return index;
			}
		}
	}
};

class anotherSolution{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
	{
        map <int,int> myMap;
        map<int,int>::iterator ite;
        vector<int> ans;
        myMap.insert(pair<int,int>(target - nums[0],0));
        
        for (int i = 1;i<nums.size();i++)
		{
            ite = myMap.find(nums[i]);
            if(ite!=myMap.end())
			{
                ans.push_back(ite->second);
                ans.push_back(i);
                return ans;
            }
            myMap.insert(pair<int,int>(target - nums[i],i));
        }
        return ans;
    }
};

int main(){
	int myarray[] = {2,7, 11, 15};
	vector<int> foo (myarray, myarray + sizeof(myarray) / sizeof(int) );
	
	anotherSolution a;
	vector<int> res = a.twoSum(foo, 9);
	
	for (unsigned int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	} 

	return 0;
}

