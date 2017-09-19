import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
   public static int j=0;
   public static void inorder(int ar[],int ino[],int i,int n)
    {
    if(i>=n)
        {
        return;
    }
        else{
           inorder(ar,ino,2*i+1,n);
            ino[j++]=ar[i];
            inorder(ar,ino,2*i+2,n);
        }
    
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        
        while(t>0)
            {
            t--;
           int n=sc.nextInt();
            int ar[]=new int[n];
            int i=0;
            int ino[]=new int[n];
           for(int j=0;j<n;j++)
                {
                ar[i++]=sc.nextInt();
            }
            Solution.j=0;
            Solution.inorder(ar,ino,0,n);
            java.util.Arrays.sort(ar); 
            int mods=0;
            for(i=0;i<n;i++)
                {
                   if(ino[i]!=ar[i])
                    {
                    int j;
                    for(j=0;j<n;j++)
                        {
                        if(ar[j]==ino[i])
                            {
                            int temp=ar[i];
                            ar[i]=ar[j];
                            ar[j]=temp;
                            mods++;
                            break;
                        }
                    }
                }
            }
         System.out.println(mods);   
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}
