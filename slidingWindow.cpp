#include <algorithm>
#include<iostream>
#include<deque>
using namespace std;
#define LL long long
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
//algorithm here: http://home.tiac.net/~cri/2001/slidingmin.html
int computeSlidingWindow(int a[], int n, int w){
        if(n<=0 || n<w){
                cout<<"invalid input"<<endl;
                return -1;
        }
        deque<int> dq; //keep indices of a[] inside deque
        REP(i,n){
                if(i >=w && dq[0] <= i-w )
                        dq.pop_front();
                while(!dq.empty() && a[dq.back()] > a[i])
                        dq.pop_back();
                dq.push_back(i);
                if(i >= w-1)
                        cout<<a[dq.front()]<<" " ;
        }
}

int main() {
        //int a[] = {4,3,2,1,5,7,6,8,9};
        int n,w;
        cout<<"enter array size: ";
        cin>> n;
        cout<<endl<<"enter the array: ";
        int a[n];
        REP(i,n) cin>>a[i];
        cout<<endl<<"enter window size: ";
        cin>>w;
        computeSlidingWindow(a, n, w);
        return 0;
}

