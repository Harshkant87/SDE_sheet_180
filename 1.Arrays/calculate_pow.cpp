// You are given two numbers ’x’(it’s a float), and ’n’(it’s a integer).



// Your task is to calculate ‘x’ raised to power ‘n’, and return it.



// The expected time complexity is ’O(logn)’, and the expected space complexity is ’O(1)’, where ‘n’ is the power to which the number should be raised.



// Note:
// In the output, you will see the number returned by you upto 6 decimal places.

double myPow(double x, int n) {
    // Write Your Code Here
    if(n==0)
        return 1;
    if(n < 0){
        n = abs(n);
        x=1/x;
    }

    if(n%2 == 0){
        return myPow(x*x, n/2);
    }
    else{
        return x*myPow(x, n - 1);
    }
}