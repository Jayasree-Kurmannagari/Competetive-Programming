//Codeforces
//Problem 318A Even Odds
//<a href="https://codeforces.com/contest/318/problem/A">

import math
n,k=map(int,input().split());
if(k<=math.ceil(n/2)): 
  print(2*k-1);
else:
    if(n%2==0):
      print(2*(k-math.ceil(n/2)));
    else: 
      print(2*(k-1-math.floor(n/2)));
