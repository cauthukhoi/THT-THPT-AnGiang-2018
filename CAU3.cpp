#include <bits/stdc++.h>

using namespace std;
int n,a[30001],dc[30001]={0},dinh[30001]={0};

int main(){
    fstream inp; inp.open("CAU3.INP");
    fstream oup; oup.open("CAU3.OUT", ios::out);
    inp>>n;
    for (int i=1;i<=n;i++) inp>>a[i];

    for(int i=1;i<=n;i++){
        int dmax=0,pmax=0;
        for (int j=1;j<=i-1;j++) if (dmax<dc[j] && a[i]>a[j]) {dmax=dc[j]; pmax=j;}
        dc[i]=dc[pmax]+1;
        dinh[i]=pmax;
    }

    /*for(int i=1;i<=n;i++) cout<<i<<" "; cout<<endl;
    for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
    for(int i=1;i<=n;i++) cout<<dc[i]<<" "; cout<<endl;
    for(int i=1;i<=n;i++) cout<<dinh[i]<<" "; cout<<endl;*/

    int fmax=0,pos=0;
    for (int i=1;i<=n;i++) if (fmax<dc[i]) {fmax=dc[i];pos=i;}
    fmax+1;
    oup<<fmax<<endl;
    int d1[fmax+1],d2[fmax+1],m=fmax;
    while (m>=0){
        d1[m]=a[pos];d2[m]=pos;
        pos=dinh[pos];
        m--;
    }
    for(int i=1;i<=fmax;i++) oup<<d1[i]<<" "<<d2[i]<<endl;
}
