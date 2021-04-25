#include <bits/stdc++.h>

using namespace std;
string s1,s2; int pos,lmax=0;

int main(){
    fstream inp; inp.open("CAU2.INP");
    fstream oup; oup.open("CAU2.OUT", ios::out);
    inp>>s1; inp>>s2;
    oup<<s1<<endl; oup<<s2<<" ";

    for (int i=0;i<s1.length();i++)
        if(s1[i]==s2[0]) {
            int j=i+1,cnt=1;
            while(s1[j]==s2[j-i]) {cnt++;j++;}
            if (cnt>lmax) {lmax=cnt;pos=i+1;}
        }
    oup<<pos<<" "<<lmax;
}
