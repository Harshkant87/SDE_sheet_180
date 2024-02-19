// You are given two versions numbers A and B as a string. Your task is to compare them and find out which one of them is a newer version.

// Note:
// There are no leading zeros in any of the strings except in the case of zero itself. Note that, the leading zeroes are not allowed even after a '.' ie: 121.005 is an invalid version, while 121.5 is an valid version.
// For Example:
// A = “1.23.45”, B = “1.23.456”

// The first two parts of both the strings are the same i.e 1 and 23 and the third part of B is greater than the third part of A i.e. 45 < 456, thus string B is the latest version.

#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    // Write your code here
    int n1 = a.size();
    int n2 = b.size();
    int i = 0; 
    int j = 0;

    while(i < n1 || j < n2){
        long num1 = 0; // use long to avoid failed test case for large test case
        long num2 = 0; // use long to avoid failed test case for large test case

        while(i < n1 && a[i] != '.' ){

            num1 = num1*10 + (a[i] - '0');
            i++; 

        }

        while(j < n2 && b[j] != '.' ){

            num2 = num2*10 + (b[j] - '0');
            j++; 

        }

        if(num1>num2) return 1;
        else if(num1<num2) return -1;
        i++;
        j++;

    }

    return 0;
}