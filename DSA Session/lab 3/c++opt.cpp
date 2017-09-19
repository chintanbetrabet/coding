     
       // #include<bits/stdc++.h>
        #include<iostream>
        #include<algorithm>
        using namespace std;
        using namespace std;
         
        void swap(int &a,int &b) //simple swap
        {
        int t=a;
        a=b;
        b=t;
        }
        int binary_search(int e,int ar[],int size) //iterative binary search
        {
        int hi=size-1;
        int lo=0;
        while(hi>lo)
        	{
        	int mid=(hi+lo)/2;
        		if(ar[mid]==e)
        			{
        			return mid;
        			}
        	else if(ar[mid] >e) hi=mid-1;
        	else lo=mid+1;
        	}
        return (hi+lo)/2;
         
        }
         
        int minswap(int ar[],int size) //main helper function
        {
        
        int sorted[size];
        for(int i=0;i<size;i++)sorted[i]=ar[i]; //creates a copy of the array
         
        sort(sorted,sorted+size);  //sort the copied array
        /*
        uses <algorithm> takes para1 as pointer to start
        and para 2 as pointer to end in-place sort
        */
        int mods=0;
        int inplace=0;
        int i=0;
        int nomod=0;
        while(nomod<size) //break when no modifications are done in a traversal
        	{
        	if(ar[i]!=sorted[i])
        		{
        			int v=binary_search(ar[i],sorted,size); 
        			/* find the position where ar[i] should be
        			 in sorted sequence */
        			swap(ar[i],ar[v]);	// put it in place
        			mods++;	//update modifications
        			nomod=0; //reset consecutive elements with no swaps
        		}
        	else
        		{
        		nomod++; //elements in correct position
        		}
        	i+=1;
        	i%=size;
        	}
         
        return mods;
        }
        int pos=0; // global value to decide length of inorder traversal
        int ino[1123456]; //store inorder traversal
        void inorder(int ar[],int ind,int n) //do inorder using index
        {
        if(ind>=n)return; //check for null
        inorder(ar,ind*2+1,n); //left child
        ino[pos++]=ar[ind];
        inorder(ar,2*ind+2,n); //right child
        }
        int main()
        {
         int t;
         cin>>t;
         while(t--)
         {
         pos=0;
         for(int i=0;i<1123456;i++) // reset the inorder for each testcase not needed if array but good practice
         {
         ino[i]=0;
         }
         int n;
         cin>>n;
         int ar[n];
         int i=0;
         int k=n;
         while(n--)
         {
         cin>>ar[i++];
         }
         
         inorder(ar,0,k);
         
        cout<<myminswap(ino,k)<<endl;
     	}    
        }
     
