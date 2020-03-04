#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

class Solution {
public:
    /**
     * @param k: An integer
     * @param n: An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
        // write your code here
        int count = 0;
        if (k == 0) {
            count = 1;
        }
        for (int i = 1; i <= n; i++) {
            int number = i;
            while (number > 0) {
                if (number % 10 == k) {
                    count += 1;
                } 
                number /= 10;
            }
        }       
        return count;        
    }
};

int test(){
    int k;
    int n;
    int time = 0;
    int result;
    Solution test;
    //cout<<test.digitCounts(1,12)<<endl;
    while(time < 1000){
        k = rand()%9;
        n = rand()%100000;
        result = test.digitCounts(k,n);
        time += 1;
        //cout<<"time is: "<<time<<endl;
    }
    return 0;
}

int main(){
    clock_t start,ends;
    start=clock();
    test();
    ends=clock();
    cout<<"test use time is: "<<(ends-start)/1000000.000000000000000<<"s"<<endl;
}