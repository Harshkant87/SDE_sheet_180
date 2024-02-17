// Afzal has been working with an organization called 'Money Traders for the past few years. The organization is in the money trading business. His manager assigned him a task.


// Given an array ’prices’ which denotes stock prices for ’n’ days, e.g., 'prices[ i ]' = price of the stock at ‘ith’ day, Find the stock's span for each day.


// The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backward) for which the price of the stock was less than today's price.



// Example:
// Input: ‘n’ = 7,  ‘prices’ = [100, 80, 60, 70, 60, 75, 85]

// Output: [1, 1, 1, 2, 1, 4, 6]

#include<bits/stdc++.h>

vector<int>prevGreElem(vector<int>& prices){
    int n = prices.size();
    stack<int>s;
    vector<int>ans(n, 1);

    for(int i = 0; i < n; i++){
        int curr = prices[i];

        while(!s.empty() && prices[s.top()] < curr){
            s.pop();
        }

        if(!s.empty())
            ans[i] = s.top();
        else 
            ans[i] = -1;

        s.push(i);
    }
    return ans;
}


vector<int> findStockSpans(vector<int>& prices) {
    // Write your code here.
    vector<int>prevG = prevGreElem(prices);
    int n = prices.size();
    vector<int>ans(n, 1);

    for(int i = 0; i < n; i++){
        ans[i] = i - prevG[i];
    }
    return ans;
}