#include <iostream>
#include <conio.h>

using namespace std;

int max_sum(int A[],int N)
{
  int sum = 0;
  int wtSum = 0;
  
  int rtPtr = N-1;
  int ltPtr = 1;
  int sub = 0;
  int ans = 0;
    
  for (int i=1; i<N; i++) {
    sum += A[i];
    wtSum += i*A[i];
  }
    
  for (int i=0; i<N; i++) {
    sub = (N-1) * A[rtPtr];
    ltPtr = --ltPtr < 0 ? (ltPtr + N) % N : ltPtr % N;

    sum = sum + A[ltPtr] - A[rtPtr];
    rtPtr = --rtPtr < 0 ? (rtPtr + N) % N : rtPtr % N;

    wtSum = wtSum + sum - sub;
    ans = max(ans, wtSum);
  }

  return ans;
}