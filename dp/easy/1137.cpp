//https://leetcode-cn.com/problems/n-th-tribonacci-number/

#include <iostream>
#include <vector>

using namespace std;

int tribonacci(int n) {
    if(n<2){
        return n;
    }else if (n==2)
    {
        return 1;
    }
    
    int a=0,b=0,c=1,d=1;
    for(int i=2;i<n;i++){
        a=b+c+d;
        b=c;
        c=d;
        d=a;
    }
    return d;
}

int main(){
    for(int i=0;i<10;i++){
        cout<<"i:"<<i<<"\t tribonacci:"<<tribonacci(i)<<endl;
    }
   return 0;
}
