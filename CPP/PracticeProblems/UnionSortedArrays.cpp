#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Unsolved
// https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int ptr1 = 0;
        int ptr2 = 0;
        int top = 0;
        
        vector<int> unionArr;
        int i=0, j=0;
        
        while (i<n || j<m) {
            if (arr1[i] < arr2[j] && i<n) {
                if (top < arr1[i]) {
                    unionArr.push_back(arr1[i]);
                    top = arr1[i];
                }

                i++;
            } else if (arr1[i] > arr2[j] && j<m) {
                if (top < arr2[j]) {
                    unionArr.push_back(arr2[j]);
                    top = arr2[j];
                }
    
                j++;
            } else {
                // i++;
                if (top < arr1[i]) {
                    unionArr.push_back(arr1[i]);
                    top = arr1[i];
                }
    
                i++;
                // j++;
            }
        }
        
        return unionArr;
        //Your code here
        //return vector with correct order of elements
    }
};

class Solvedution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int ptr1 = 0;
        int ptr2 = 0;
        int top = 0;
        
        vector<int> unionArr;
        int i=0, j=0;
        
        while (i<n && j<m) {
            if (arr1[i] < arr2[j]) {
                if (top < arr1[i]) {
                    unionArr.push_back(arr1[i]);
                    top = arr1[i];
                }

                i++;
            } else if (arr1[i] > arr2[j]) {
                if (top < arr2[j]) {
                    unionArr.push_back(arr2[j]);
                    top = arr2[j];
                }
    
                j++;
            } else {
                if (top < arr1[i]) {
                    unionArr.push_back(arr1[i]);
                    top = arr1[i];
                }
                i++;
                j++;
            }
        }
        
        while (i < n) {
            if (top < arr1[i]) {
                unionArr.push_back(arr1[i]);
                top = arr1[i];
            }
            i++;
        }
        
        while (j < m) {
            if (top < arr2[j]) {
                unionArr.push_back(arr2[j]);
                top = arr2[j];
            }
            j++;
        }
        
        return unionArr;
        //Your code here
        //return vector with correct order of elements
    }
};

// 2 3
// 1 42
// 21 25 37

// 3 14
// 15 24 42
// 4 8 10 12 13 17 19 24 29 30 38 42 45 48

// 13 3
// 13 17 18 19 20 22 22 27 36 39 46 48 50
// 4 12 45

// 6 6
// 1 5 9 13 17 21
// 3 6 9 12 18 21