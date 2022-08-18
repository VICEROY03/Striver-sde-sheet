class Solution {
public:
    int rec(vector<int>& prices, vector<int>::iterator start, int maxDiff){
        int mini;
        vector<int>::iterator maxi;
        mini = min_element(start, prices.end())-prices.begin();
        maxi = max_element(start, prices.end());
        if(mini<=maxi-prices.begin())
            return max(prices[maxi-prices.begin()]-prices[mini], maxDiff);
        maxDiff = max(*maxi-*min_element(start, maxi), maxDiff);
        maxi++;
        return rec(prices, maxi, maxDiff);
    }
    int maxProfit(vector<int>& prices) {
        return rec(prices, prices.begin(), 0);
    }
};