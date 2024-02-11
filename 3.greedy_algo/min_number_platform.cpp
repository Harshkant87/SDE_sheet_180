

int calculateMinPatforms(int ar[], int dt[], int n) {
    // Write your code here.
    sort(ar, ar + n);
    sort(dt, dt + n);

    int ans = 1;
    int count = 1;
    int i = 1, j = 0;

    while(i < n && j < n){
        if(ar[i] <= dt[j]){ //departure is lesser than arrival
            i++;
            count++;
        }
        else{
            count--;
            j++;
        }
        ans = max(ans, count);
    }
    return ans;
}