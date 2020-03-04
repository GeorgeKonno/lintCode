#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

class Solution {  
public:  
    /* 
      @param a: An integer 
      @param b: An integer 
      @return: The sum of a and b  
     */  
    int aplusb_nonrecursive(int a, int b) {  
        int result=a^b,carry=(a&b)<<1;  
        //cout<<"result is:"<<result;
        //cout<<"carry is:"<<carry;
        while(carry!=0){   
            a=result^carry;  
            carry=(result&carry)<<1;  
            result=a;  
            //cout<<"result is:"<<result;
            //cout<<"carry is:"<<carry;
        }  
        return result;  
    }  
    int aplusb_recursive(int a, int b) {  
        return b==0?a:aplusb_recursive(a^b,(a&b)<<1);
    } 
};  

void test(string testname){
    Solution test;
    int result;
    int a;
    int b;
    int count = 0;
    if(testname == "nonrecursive"){
        while(count<100000000){
            a = rand()%1000000;
            b = rand()%1000000;
            result = test.aplusb_nonrecursive(a,b);
            bool correct = result == (a + b);
            if(correct){
                count += 1;
                //cout<<a<<"+"<<b<<" result is: "<<result<<endl;
            }
            else{
                cout<<"failed"<<endl;
                break;
            }
        }
    }
    else if(testname == "recursive"){
        while(count<100000000){
            a = rand()%1000000;
            b = rand()%1000000;
            result = test.aplusb_recursive(a,b);
            bool correct = result == (a + b);
            if(correct){
                count += 1;
                //cout<<a<<"+"<<b<<" result is: "<<result<<endl;
            }
            else{
                cout<<"failed"<<endl;
                break;
            }
        }
    }
    cout<<"run "<<count<<" times"<<endl;
}

int main(){
    clock_t start,ends;
    start=clock();
    test("nonrecursive");
    ends=clock();
    cout<<"test1 use time is: "<<(ends-start)/1000000.000000000000000<<"s"<<endl;
    start=clock();
    test("recursive");
    ends=clock();
    cout<<"test2 use time is: "<<(ends-start)/1000000.000000000000000<<"s"<<endl;
}