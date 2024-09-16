/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Algorithms;

/*package whatever //do not write package name here */

import java.util.*;

public class maxIndex {
    
    //AUXILLARY ARRAY SOLUTION
    public static int maxIndexDiff(int[] A)
    {
        int N = A.length;
        int[] rMax = new int[N];
        int[] lMin = new int[N];
        
        rMax[N-1] = A[N-1];
        for(int i=N-2; i>=0; i--)
        {
            rMax[i] = Math.max(rMax[i+1], A[i]);
        }
        
        lMin[0] = A[0];
        for(int i=1; i<N; i++)
        {
            lMin[i] = Math.min(lMin[i-1], A[i]);
        }
        
        for(int i: lMin)
        System.out.print(i+" ");
        
        for(int i: rMax)
        System.out.print(i+" ");
        
        
        int i=0, j=0, maxDiff = Integer.MIN_VALUE;
        
        while(i<N && j<N)
        {
            if(A[i]>=A[j])
            {
                maxDiff = Math.max(i-j, maxDiff);
                i++;
            }
            
            else
                j++;
        }
        
        return maxDiff;
        
    }
    
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while(T-->0)
        {
            int N = sc.nextInt();
            int[] A = new int[N];
            boolean toggle = false;
            

            for(int i=0; i<N; i++)
                A[i] = sc.nextInt();
            
            if(N==1)
                System.out.println("0");

            for(int i=N-1; i>1; i--)
            {
                for(int j=0; j<N-i; j++)
                {
                    if(A[j]<=A[j+i])
                    {
                        System.out.println(i);
                    }
                }
                
                if(toggle)
                    break;
            }
            
            int ans = maxIndexDiff(A);
            
            System.out.println(ans);

        }
    }
}