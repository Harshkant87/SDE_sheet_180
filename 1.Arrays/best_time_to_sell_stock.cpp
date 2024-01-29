// You are given an array of integers 'prices' of size 'n', where ‘prices[i]’ is the price of a given stock on an ‘i’-th day.



// You want to maximize the profit by choosing a single day to buy one stock and a different day to sell that stock.



// Please note that you can’t sell a stock before you buy one.



// Return the maximum profit you can achieve from this transaction.



// Example :
// Input: ‘prices’ =[7, 1, 5, 4, 3, 6]

// Output: 5

// Explanation: Purchase stock on day two, where the price is one, and sell it on day six, where the price is 6, profit = 6 - 1 = 5.

// Hence we return 5.

int bestTimeToBuyAndSellStock(vector<int>&prices) {
    // Write your code here.
    int min_price = INT_MAX;
    int max_profit = 0;

    for(int price: prices){
        min_price = min(price, min_price);
        max_profit = max(max_profit, price - min_price);
    }
    return max_profit;
}