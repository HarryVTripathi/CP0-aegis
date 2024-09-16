// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

# include <algorithm>

class Solution {
  public:
    int kG;
    int sizeVecG;
    int diff;

    void setHt(vector<int> v, int ind, int currHt, int minHt, int maxHt) {
        minHt = min(currHt, minHt);
        maxHt = max(currHt, maxHt);

        if (ind < sizeVecG - 1) {
            if (v[ind+1] - kG >= 0)
                setHt(v, ind+1, v[ind+1] - kG, minHt, maxHt);
            setHt(v, ind+1, v[ind+1] + kG, minHt, maxHt);
        } else {
            diff = min(maxHt - minHt, diff);
        }
    }

    int getMinDiff(int arr[], int n, int k) {
        vector<int> v(arr, arr + n);
        kG = k;
        sizeVecG = n;
        diff = INT_MAX;
        sort(v.begin(), v.end());
        setHt(v, 0, v[0]+kG, INT_MAX, INT_MIN);

        return diff;
    }
};

// 3
// 5 6 7 8 9 13

// 3
// 5 10 110

// 3
// 5 10

// 5
// 7 9 7 7 5 10 2 6 5 6