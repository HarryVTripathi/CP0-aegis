/*
https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0
 */
package Algorithms;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Harry
 */
public class StockBuySell {
    public static void main (String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while(T-->0)
        {
            int N = sc.nextInt();
            int[] A = new int[N];
            int sd = 0, maxPro = 0, pro = 0;
            ArrayList<String> al = new ArrayList<String>();

            for(int i=0; i<N; i++)
                A[i] = sc.nextInt();

            for(int i=0; i<N; i++)
            {
                pro = A[i] - A[sd];

                //System.out.println(sd+" "+i);

                if(pro>=maxPro)
                {
                    maxPro = pro;

                    if(i==N-1)
                    {
                        String st = "("+sd+" "+i+")";
                        al.add(st);
                    }
                }

                else
                {
                    if(maxPro>0)
                    {
                        String st = "("+sd+" "+(i-1)+")";
                        al.add(st);
                    }

                    maxPro = 0;
                    sd = i;
                }
            }

            if(al.isEmpty())
                System.out.print("No Profit");

            else
            {
                for(String s : al)
                    System.out.print(s+" ");
            }

            System.out.println("");
        }
    }


}
