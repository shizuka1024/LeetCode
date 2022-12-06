/*
 * Leetcode Medium 46. Permutations
 * author: shizuka1024
 * AC(C++) 4ms 7.1MB
 */
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#include "helper.h"

void f(int l, vector<int>& p){  //l=level,p=path
  if(l == 3){
    cout<< p[0] <<" "<< p[1] << " " << p[2] << endl;
  }
  for(p[l] = 1; p[l] <=3; p[l]++){
    if(count(begin(p), begin(p) + l, p[l]) != 0){
      continue;
    }
    f(l +1, p);
  }
}

int main(){
  vector<int> path(3);
  f(0, path);
  return 0;
}
