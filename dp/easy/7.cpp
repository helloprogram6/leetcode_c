//https://leetcode-cn.com/problems/climbing-stairs/
#include <iostream>
#include <vector>

using namespace std;
int climbStairs(int n) {
    if(n==1||n==2){
        return n;
    }
    int a=1,b=2,res=0;
    for(int i=2;i<n;i++){
        res=a+b;
        a=b;
        b=res;
    }
    return res;
}
int main(){
    for(int i=1;i<10;i++){
        cout<<"i:"<<i<<"-->"<<climbStairs(i)<<endl;
    }
    return 0;
}
