#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long trailingZeros(long n) {
        // write your code here, try to do it without arithmetic operators.
        long numoftrailingzero = 0;       
        while (n >= 5){
            n = n / 5;
            numoftrailingzero += n;
        }
        return numoftrailingzero;
    }
};

long test(long n){
    Solution test;
    long count = 0;
    long result;
    while(count < n){
        result = test.trailingZeros(count);
        cout<<"the count: "<<count<<" 's result is: "<<result<<endl;
        count += 1;
    }
}

int main(){
    clock_t start,ends;
    start=clock();
    test(100000);
    ends=clock();
    cout<<"test use time is: "<<(ends-start)/1000000.000000000000000<<"s"<<endl;
} 