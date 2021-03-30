#include<iostream>
#include<vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy = 0;
        int sell = 0;
        int loss = 0;
        int gain = 0;
        int sz = prices.size();
        int profit = 0;
        int i = 1;
        for(; i < sz; i++)
        {
            if((prices[i-1] < prices[i])){
		
                if(!gain) {
                    buy = i - 1;
                    gain = 1;
                }
		std::cout<<buy<<" Buy<-->Gain "<<gain<<'\n';         
            } else {
                if(gain) {
                    profit += prices[i-1] - prices[buy];
                    gain = 0;
		    std::cout<<"NO Entry";
                }
            }
        }
		std::cout<<buy<<" Buy<-->Gain "<<gain<<"   "<<i<<".   "<<sz<<'\n';         

        if(gain && (i == sz))
            profit += prices[sz-1] - prices[buy];
        return profit;
    }
};

int main(){
	std::vector<int> vec = {1,2,3,4,5};
	std::cout<<Solution().maxProfit(vec);
}