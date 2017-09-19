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
    public static int bins(int ar[],int v,int h,int l)
        {
       
        int mid=(h+l)/2;
        // System.out.println(h+" "+l+" "+v+" "+mid+" "+ar[mid]);
        if(ar[mid]==v)return mid;
        if(ar[mid]>v)return bins(ar,v,mid,l);
        return bins(ar,v,h,mid);
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
           for(int k=0;k<n;k++)
                {
                ar[k]=sc.nextInt();
            }
            Solution.j=0;
            Solution.inorder(ar,ino,0,n);
            java.util.Arrays.sort(ar);
             
           int mods=0;
           int nomods=0;
           int ind=0;
          while(nomods<n)
                {
                if(ino[ind]!=ar[ind])
                    {
                    int k=Solution.bins(ar,ino[ind],n,0);
                    int temp=ino[k];
                    ino[k]=ino[ind];
                    ino[ind]=temp;
                            mods++;
                            nomods=0;
                               

                    }
                else nomods++;
                ind+=1;
                ind%=n;
                }
             System.out.println(mods);
             
            }
           
        
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
            
    }
}
