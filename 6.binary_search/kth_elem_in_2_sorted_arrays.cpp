// Ninja wants to serve food to needy people. So, he bought Ladoos from a sweet shop and placed them on plates. There can be any number of Ladoos present in a plate.

// Plates containing Ladoos are placed in two rows. Each row is sorted in increasing order by the number of Ladoos in a plate.

// For example :
// ‘ROW1’ :  [2, 5, 8, 17] and  ‘ROW2’ :  [1, 4, 8, 13, 20]
// Now people come one by one in a line to take plates of Ladoos from Ninja. Ninja picks the two plates in front, one from each row and gives that plate to people in which the number of ladoos is the smallest (if both plates contain equal numbers of ladoos then he serves any plate from the two plates) and places the other plate back to its position.

// For Example :
// If ‘ROW1’ is [2, 5, 8, 17] and ‘ROW2’ is [1, 4, 8, 13, 20], then Ninja picks the first plates from each rows, plate containing 2 ladoos from ‘ROW1’ and a plate containing 1 ladoo from ‘ROW2’. 
// Then he gives the plate with 1 Ladoo to the first person in line and places the other plate back to its position.

#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &arr1, vector<int> &arr2, int m, int n, int k) {
    // Write your code here.
        if(m > n) {
        return ninjaAndLadoos(arr2, arr1, n, m, k); 
    }
        
    int low = max(0,k-m), high = min(k,n);
        
    while(low <= high) {
        int cut1 = (low + high) >> 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 1; 
}