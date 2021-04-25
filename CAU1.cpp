#include <bits/stdc++.h>

using namespace std;
int n,S1,S2=0,a[100];

int main(){
    fstream inp; inp.open("CAU1.INP");
    fstream oup; oup.open("CAU1.OUT", ios::out);
    inp>>n;
    for(int i=1;i<=n;i++) {
        inp>>a[i];
        S1+=a[i];
    }
    int L,R;
    for (int i=1;i<=n;i++)
        if (S2<a[i]) {S2=a[i];L=i;R=i;}
    S1-=S2;
    while(S2<S1){
        if (L-1==0) {R++; S2+=a[R]; S1-=a[R]; continue;}
        if (R+1==n+1) {L--; S2+=a[L]; S1-=a[L]; continue;}
        int dis=S1-S2;
        if (abs(dis-a[L-1])<abs(dis-a[R+1])) {L--; S2+=a[L]; S1-=a[L];}
        else {R++; S2+=a[R]; S1-=a[R];}
    }
    if (R<n) {
        for (int i=1;i<=L-1;i++) oup<<a[i]<<" ";
        for (int i=R+1;i<n;i++) oup<<a[i]<<" ";
        oup<<a[n]<<endl;
    } else { for (int i=1;i<L-1;i++) oup<<a[i]<<" "; oup<<a[L-1]<<endl;}
    for (int i=L;i<R;i++) oup<<a[i]<<" "; oup<<a[R];
}
