#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        if(sz > 1){
            vector<int>::iterator it = nums.begin();
            if(k == 1)
            {
                int temp = nums[sz-1];
                nums.erase(it + sz - 1);
                nums.insert(it, temp);
            } else if(k < sz ) {
                nums.insert(it, it + sz - k, it + sz);
                vector<int>::iterator it2 = nums.begin();
                nums.erase(it2 + sz, it2+sz+k);
               
            } else if (k > sz) {
                 for(int i = 0; i < k; i++)
                {
                    int temp = nums[sz-1];
                    nums.erase(it + sz - 1);
                    nums.insert(it, temp);
                 }
            }
        }
    }
};

int main(){
	vector<int> vec{1,2,3,4,5,6};
	Solution s;
	s.rotate(vec, 2);
	for(auto x : vec)
		cout<<x<<" ";

}