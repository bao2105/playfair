#include <iostream>
#include <string>
#include <cstring>
#include<vector>
#include<map>
using namespace std;

void encryption();
void decryption();

int main() {
    int chon;
	while(true){
		cout<<"\n --- Play Fair Cipher ---\n"<<endl;
		cout<<"press 1 for encryption "<<endl;
		cout<<"press 2 for decryption"<<endl;	
		cout<<"---------------------------------"<<endl;
		cin>>chon;
		switch(chon){
			case 1:
                encryption();
                break;
            case 2:
                decryption();
                break;
		}
}}

void encryption()  {
    int i,j,k,n;
    cout<<"Enter the message"<<endl;
    string s,origin;
    cin>> s ;
    getline(cin,origin);
    cout<<"Enter the key"<<endl;
    string key;
    cin>>key;
    for(i=0;i<origin.size();i++){
        if(origin[i]!=' ')
            s+= origin[i];
    }
    vector<vector<char> > a(5,vector<char>(5,' '));
    n=5;
    map<char,int> mp;
    k=0;
    int pi,pj;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            while(mp[key[k]]>0&&k<key.size()){
                k++;
            }
            if(k<key.size()){
                a[i][j]=key[k];
                mp[key[k]]++;
                pi=i;
                pj=j;
            }
            if(k==key.size())
            break;
        }
        if(k==key.size())
            break;
    }
    k=0;
    for(;i<n;i++){
        for(;j<n;j++){
            while(mp[char(k+'a')]>0&&k<26){
                k++;
            }
            if(char(k+'a')=='j'){
                j--;
                k++;
                continue;
            }
            if(k<26){
                a[i][j]=char(k+'a');
                mp[char(k+'a')]++;
            }
        }
        j=0;
    }
    string ans;
    if(s.size()%2==1)
        s+="x";
    for(i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1])
            s[i+1]='x';
    }
    map<char,pair<int,int> > mp2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mp2[a[i][j]] = make_pair(i,j);
        }
    }
    
    for(i=0;i<s.size()-1;i+=2){
        int y1 = mp2[s[i]].first;
        int x1 = mp2[s[i]].second;
        int y2 = mp2[s[i+1]].first;
        int x2 = mp2[s[i+1]].second;
        if(y1==y2){
            ans+=a[y1][(x1+1)%5];
            ans+=a[y1][(x2+1)%5];
        }
        else if(x1==x2){
            ans+=a[(y1+1)%5][x1];
            ans+=a[(y2+1)%5][x2];    
        }
        else {
            ans+=a[y1][x2];
            ans+=a[y2][x1];
        }
    }
    cout<<"\nencryption is: "<< ans<<'\n';
    return;
}

void decryption() {
   int i,j,k,n;
    cout<<"Enter the encrypted message\n";
    string s;
    cin>>s;
    cout<<"Enter the key\n";
    string key;
    cin>>key;
    vector<vector<char> > a(5,vector<char>(5,' '));
    n=5;
    map<char,int> mp;
    k=0;
    int pi,pj;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            while(mp[key[k]]>0&&k<key.size()){
                k++;
            }
            if(k<key.size()){
                a[i][j]=key[k];
                mp[key[k]]++;
                pi=i;
                pj=j;
            }
            if(k==key.size())
            break;
        }
        if(k==key.size())
            break;
    }
    k=0;
    for(;i<n;i++){
        for(;j<n;j++){
            while(mp[char(k+'a')]>0&&k<26){
                k++;
            }
            if(char(k+'a')=='j'){
                j--;
                k++;
                continue;
            }
            if(k<26){
                a[i][j]=char(k+'a');
                mp[char(k+'a')]++;
            }
        }
        j=0;
    }
    string ans;
    map<char,pair<int,int> > mp2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mp2[a[i][j]] = make_pair(i,j);
        }
    }
    for(i=0;i<s.size()-1;i+=2){
        int y1 = mp2[s[i]].first;
        int x1 = mp2[s[i]].second;
        int y2 = mp2[s[i+1]].first;
        int x2 = mp2[s[i+1]].second;
        if(y1==y2){
            ans+=a[y1][(x1-1)%5];
            ans+=a[y1][(x2-1)%5];
        }
        else if(x1==x2){
            ans+=a[(y1-1)%5][x1];
            ans+=a[(y2-1)%5][x2];    
        }
        else {
            ans+=a[y1][x2];
            ans+=a[y2][x1];
        }
    }
    if(ans[ans.size()-1]=='x')
        ans[ans.size()-1]='\0';
    for(i=1;i<ans.size();i++){
        if(ans[i]=='x')
            ans[i]=ans[i-1];
    }
    
    cout<<"\ndecryption is: "<<ans<<'\n';
    return;
}

