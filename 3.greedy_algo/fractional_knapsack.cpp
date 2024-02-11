// You have been given weights and values of ‘N’ items. You are also given a knapsack of size ‘W’.

// Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.

// Note:
// You are allowed to break the items.
// Example:
// If 'N = 4' and 'W = 10'. The weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. 
// Then the best way to fill the knapsack is to choose items with weight 6, 1 and  3. The total value of knapsack = 3 + 6 + 4 = 13.00 

#include <bits/stdc++.h>

using namespace std;

 

double maximumValue(vector<pair<int, int>>& items, int n, int w) {

    vector<pair<double, pair<int, int>>> valuePerWeight;

 

    for (int i = 0; i < n; i++) {

        double ratio = static_cast<double>(items[i].second) / items[i].first;

        valuePerWeight.push_back({ratio, {items[i].first, items[i].second}});

    }

 

    sort(valuePerWeight.rbegin(), valuePerWeight.rend());

 

    double totalValue = 0.0;

    int currentWeight = 0;

 

    for (int i = 0; i < n; i++) {

        if (currentWeight + valuePerWeight[i].second.first <= w) {

            currentWeight += valuePerWeight[i].second.first;

            totalValue += valuePerWeight[i].second.second;

        } else {

            double remainingWeight = w - currentWeight;

            totalValue += (valuePerWeight[i].first * remainingWeight);

            break;

        }

    }

 

    return totalValue;

}

 