// https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1

class Solution{
  public:
  int canRepresentBST(int arr[], int N)
  {
    stack <int> s;
    stack <int> sx;

    for (int i=0; i<N; i+=1) {
      if(!sx.empty() && (sx.top() > arr[i])) {
        return 0;
      }
      
      while (!s.empty() && (s.top() < arr[i])) {
        sx.push(s.top());
        s.pop();
      }
      s.push(arr[i]);
    }
    
    if (!s.empty() && !sx.empty()) {
      if (s.top() >= sx.top())
        return 1;
      else
        return 0;
    }
    else
      return 1;
  }
}