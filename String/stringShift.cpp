#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
		int sz = shift.size();
		int totShift = 0;
		for(auto x:shift)
		{
			for(auto y : x) {
				if(x == 0)
					totShift -= y;
				else id(x == 1)
					totShift += y;
			}
		}
		
		if(sz > 1) {
           		 if(k > sz)
              			  k = k - sz%k;
            		vector<int> vec(k);
            		vec.assign(s.end() - k, s.end());
            		for(int i = 0; i < (sz - k); i++)
           		 {
               			 s[sz-i-1] = s[sz-k-i-1];
           		 }
           		 for(int i = 0; i<k; i++)
              		 s[i] = vec[i];
      		  }
		return s
	}
};

int main(){
	vector<vector<int> >v;
	string s = "abcdefg";
	cout<<Solution().stringShift(s, v);
}