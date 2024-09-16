//https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0
package Algorithms;
//

import java.util.*;
import java.lang.*;
import java.io.*;
public class LongestConsecutiveSubsequence {
    
    public static int C(int[] B, int N)
    {
        int noOnes = 0, ans = 0;
        for(int i=0; i<N; i++)
        {
            if(B[i]==1)
            {
                noOnes++;
            }
            
            else
                noOnes = 0;
            
            ans = Math.max(noOnes, ans);
        }
        return ans;
    }
    
	public static void main (String[] args) 
	{
	    Scanner sc = new Scanner(System.in);
            int T = sc.nextInt();

            while(T-->0)
            {
                int N = sc.nextInt();

                int[] A = new int[N];
                int[] B = new int[N];

                for(int i=0; i<N; i++)
                    A[i] = sc.nextInt();

                Arrays.sort(A);

                for(int i=0; i<N-1; i++)
                {
                    B[i] = A[i+1] - A[i];
                    //System.out.print(B[i]+" ");
                }

                int ans = C(B,N);

                System.out.println(++ans);
            }
	}
}