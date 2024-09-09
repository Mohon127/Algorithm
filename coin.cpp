/*  //Coin Change Problem using Recursion 


#include <bits/stdc++.h>
using namespace std;
#define TC int t; cin>>t;while(t--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define nl '\n'
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ff first 
#define ss second 
#define debug(x) cout<<#x<<" "<<x<<nl;
const ll sz=2e5+7,Inf=1e9+7;


int ways[301][5001];
int n;

int solve(int i,vector<int>& coins,int amount){
  if(amount ==0) return 1;
  if(i==n) return 0;


  if(coins[i]>amount) {
    return ways[i][amount] = solve(i+1,coins,amount);
  }

  if(ways[i][amount] != -1){
     return ways[i][amount] ;
  }



  int take = solve(i, coins, amount-coins[i]);
  int skip = solve(i+1, coins, amount);
  return ways[i][amount] = take + skip;

}

 int change(int amount, vector<int>& coins) {
    memset(ways,-1,sizeof(ways));
    n = coins.size();
    return solve(0, coins,amount);
    }

int main() {
  fast;
  
  vector<int>coins{1,2,5};
  cout << change(5,coins);
  
  return 0;
}

////////////////////////////////////////////////////////////////

// >> Coin Change Problem using 2D array


#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main() {
  fast;
  int noCoin,amount;
  cin >> noCoin>> amount;

  std::vector<int> coins(noCoin);

  for(int &i: coins) cin >> i;
  sort(coins.begin(), coins.end());

 // for(auto i: coins) cout<<i<<' ';
  
  int way[noCoin+1][amount+1];

  for(int i=0 ; i<=noCoin; i++){
    for(int j=0 ; j<=amount; j++){
      if(i==0) { 
        way[i][j] = 0; 
        if(j==0){ way[i][j]=1;}
      }
      else if(coins[i-1]>j) {
        //cout << "h ";
       way[i][j] = way[i-1][j];
     }
      else { 
        //cout<<" i j " <<i<<' ' <<j <<' ' ;
       way[i][j] = way[i-1][j] + way[i][j-coins[i-1]];
       //cout << way[i][j]<<' ' << way[i-1][j]<<' ' << way[i][j-coins[i-1]] <<' ';
     }
    }
  }

  for(int i=0 ; i<=noCoin; i++){
    for(int j=0 ; j<=amount; j++){
      cout << way[i][j] <<' ';
    }cout << endl;
  }



  
  
  return 0;
}

*/


#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main() {
  fast;
  int noCoin,amount;
  cin >> noCoin >> amount;

  std::vector<int> coins(noCoin);

  for(int &i: coins) cin >> i;

  int way[noCoin+1][amount+1];

  for(int i=0 ; i<=noCoin; i++){
    for(int j=0 ; j<=amount; j++){
      if(i==0) {       
        way[i][j] = INT_MAX;
         if(j==0) way[i][j] = 0;
      }else if(coins[i-1] > j){
        way[i][j] = way[i-1][j];
      }else{
        way[i][j] = min(way[i-1][j] + 0ll,way[i][j-coins[i-1]]+1ll);
      }
    }
  }

  for(int i=0 ; i<=noCoin; i++){
    for(int j=0 ; j<=amount ; j++){
      cout << way[i][j] << ' ';
    }cout << endl;
  }


  
  
  return 0;
}