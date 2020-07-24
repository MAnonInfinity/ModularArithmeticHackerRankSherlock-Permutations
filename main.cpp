#include<bits/stdc++.h>
#define p 1000000007

using namespace std;

long long int factorial(int n){
    long long int f=1;
    for (int i=1;i<=n;i++){
        f=((f%p)*i)%p;
    }
    return f%p;
}

long long int binaryExpo(int b, int pow){
    if (b==1 || pow==0){
        return 1;
    }
    else if (b==0){
        return 0;
    }
    else if (pow==1){
        return b%p;
    }
    else{
        long long int temp = binaryExpo(b, pow / 2);
        temp = (temp * temp) % p;

        if (pow % 2 == 0) {
            return temp;
        }
        else {
            return ((b % p) * temp) % p;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        long long int nu=factorial(m+n-1)%p;
        long long int de=((factorial(m-1)%p)*(factorial(n)%p))%p;
        long long int finalDe=binaryExpo(de, p-2)%p;
        int ans=(nu*finalDe)%p;
        cout<<ans<<endl;
    }
    return 0;
}
