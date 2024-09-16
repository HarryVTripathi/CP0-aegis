package Algorithms;

import java.util.*;

class comp4 implements Comparator
{
    @Override
    public int compare(Object o1, Object o2)
    {
        Job j1 = (Job) o1;
        Job j2 = (Job) o2;
        
        if(j1.profit<j2.profit)
            return 1;

        else if(j1.profit>j2.profit)
            return -1;

        else
        {
            if(j1.profit<j2.profit)
                return 1;

            else if(j1.profit>j2.profit)
                return -1;
            
            else
                return 0;

        }
    }
}

class Job
{
    int id;
    int profit;
    int deadline;

    Job(int id, int deadline, int profit)
    {
        this.id = id;
        this.deadline = deadline;
        this.profit = profit;
    }
}

public class jobSchedulingNotDoneYet
{    
    public static void main(String[] args)
    {
        try
        {
            Scanner sc = new Scanner(System.in);
            int T = sc.nextInt();
            
            while(T-->0)
            {
                int N = sc.nextInt();
                int timer = 0, tp = 0, nJobs = 0, curDeadline = -1;
                PriorityQueue<Job> q = new PriorityQueue<Job>(N, new comp4());
                
                for(int i=0; i<N; i++)
                {
                    int id = sc.nextInt();
                    int deadline = sc.nextInt();
                    int profit = sc.nextInt();
                    
                    Job j = new Job(1, deadline, profit);
                    q.add(j);
                }
                
                while(!q.isEmpty())
                {
                    Job j = q.poll();
                    System.out.print(j.deadline+" "+j.profit);
                    if(timer<j.deadline)
                    {
                        tp = tp + j.profit;
                        nJobs++;
                        timer++;
                    }
                    
                }
                ArrayList al = new ArrayList();
                ListIterator itr = al.listIterator();
                
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
}
