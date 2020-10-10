#include<bits/stdc++.h>
using namespace std;

const int MOD=int(1e9)+7;
const int N=200000;

int add(int x,int y){
    x+=y;
    while(x>=MOD) x-=MOD;
    while(x<0) x+=MOD;
    return x;
}
int mult(int x,int y){
    return (x*1ll*y)%MOD;
}
string s;
int pow3[N]; 
int dp[N][4][4];
char buf[N];
int n;

void init_pow3(){
    pow3[0]=1;
    for(int i=1;i<N;i++)
        pow3[i]=mult(pow3[i-1],3);
}
int main(){
    int sque=0,tmp=0;
    scanf("%d",&n);
    scanf("%s",buf);
    s=buf;
    for(auto c:s)
        if(c=='?')sque++;
    cout<<"sque is"<<sque<<endl;
    init_pow3();
    dp[0][0][0]=1;
    /*dp[i][j][k]:the number of substrings that end no later than i, contains j 
    first characters of abc, and contain k question marks.*/
    for(int i=0;i<n;i++)
		for(int j=0;j<=3;j++)
			for(int k=0;k<=3;k++){
			 	if(!dp[i][j][k]) continue;
			 	dp[i + 1][j][k] = add(dp[i + 1][j][k], dp[i][j][k]);

			 	if(j<3&&(s[i]=='?'||s[i]-'a'==j)){
			 	 	tmp=(s[i]=='?'?k + 1:k);
			 	 	dp[i+1][j+1][tmp]=add(dp[i+1][j+1][nk],dp[i][j][k]);
			 	}
		   	}
    int ans=0;
    for(int i=0;i<=3;i++){
        if(sque>=i){
            ans=add(ans,mult(dp[n][3][i],pow3[sque-i]));
        }
    }
    printf("%d\n",ans);
}