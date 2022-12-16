#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, q;
    cin >> n >> q;
    vector<int> arr[n];
    for(int i=0; i<n; i++){
        int m;
        cin>>m;
        int num;
        for(int j=0; j<m; j++){
            cin>>num;
            arr[i].push_back(num);
        }
    }
    int row, col;
    
    for(int i=0;i<q; i++){
        cin>>row>>col;
        cout<<arr[row][col];
        cout<<endl;
    }
     
    return 0;
}