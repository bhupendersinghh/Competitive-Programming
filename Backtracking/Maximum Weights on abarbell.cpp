/*
    QUESTION: There is a barbell which can hold a given capacity of weights. Find the maximum weight it can hold if the weights avavilable are given

    INPUT:
    First Line: Number of weights
    Second Line: Maximum Capacity of the barbell
    Third Line: Value of weights

    OUTPUT:
    Maximum sum of weights it can hold
*/



#include<bits/stdc++.h>
using namespace std;

 void val(vector<int> weights, int mc, int sum, int j, int &ans){
    if(sum > mc)
        return;
    for(int i = j; i < weights.size(); i++) {
        sum += weights[i];
        if(ans < sum && sum <= mc)
            ans = sum;
        val(weights, mc, sum, i + 1, ans);
        sum -= weights[i];
    }
}

int main() {
    int n;
    cin>>n;
    int maxCapacity;
    cin>>maxCapacity;
    vector<int> weights(n);
    for(int i = 0; i < n; i++) {
        cin>>weights[i];
    }
    int ans = 0;
    val(weights, maxCapacity, 0, 0, ans);
    cout<<ans;
}
