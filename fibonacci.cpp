#include<iostream>
using namespace std;
int fibonacci(int num){
    int result;
    if (num<2){
        return num;
    }
    result = fibonacci(num-1) + fibonacci(num-2); 
    return result;
}
int main(){
    int num;
    cout<<"Enter Your Number: "<<endl;
    cin>>num;
    cout<<fibonacci(num)<<endl;
    return 0;

}