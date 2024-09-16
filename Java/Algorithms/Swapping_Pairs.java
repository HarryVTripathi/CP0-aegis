/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.

https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal/0
 */
package Algorithms;


import java.util.*;
import java.lang.*;
import java.io.*;

public class Swapping_Pairs 
{
	public static void main (String[] args) 
	{
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while(T-->0)
        {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int sum1 = 0;
            int sum2 = 0;
            int[] A = new int[N];
            int[] B = new int[M];
            
            HashSet<Integer> h1 = new HashSet<Integer>();
            HashSet<Integer> h2 = new HashSet<Integer>();
            
            for(int i=0; i<N; i++)
            {
                A[i] = sc.nextInt();
                sum1 = sum1+A[i];
                h1.add(A[i]);
            }
            
            for(int i=0; i<M; i++)
            {
                B[i] = sc.nextInt();
                sum2 = sum2+B[i];
                h2.add(B[i]);
            }
            
            int diff = 0, flag = -1;
            if(sum1>sum2)
            {
                diff = sum1 - sum2;
                for(int i=0; i<A.length; i++)
                {
                    if(h2.contains(diff-A[i]) && A[i]>diff-A[i])
                        flag = 1;
                }
            }
            
            else
            {
                diff = sum2 - sum1;
                for(int i=0; i<B.length; i++)
                {
                    if(h1.contains(diff-B[i]) && B[i]>diff-B[i])
                        flag = 1;
                }
            }
            
            System.out.println(flag);
            
        }
	}
}