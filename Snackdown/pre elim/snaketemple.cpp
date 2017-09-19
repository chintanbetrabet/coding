    #include<bits/stdc++.h>
    using namespace std;
     
     
    int main() {
        int t, i, j;
        cin>>t;
        while(t--)
        {
           int n, ht, curr_ht, min_cost, k,l_h, r_h;bool complete;
           long cost=0;
           cin>>n;
           vector<int> h(n, 0);
           for(i=0; i<n; i++){
                cin>>h[i];
           }
            min_cost=INT_MAX;
            for(i=0; i<n; i++){
                cost=0;
                curr_ht=min(h[i], min(i, n-1-i)+1);
                complete=false;
                
                
        outer:  while(!complete){
                    l_h=curr_ht; r_h=curr_ht; complete=true;
                    for( k=1; k<curr_ht-1; k++)
                    {
                        j=i-k;
                        if(h[j]<--l_h){
                            complete=false;
                            curr_ht=curr_ht-(l_h-h[j]);
                            goto outer;
                        }
                        j=i+k;
                        if(h[j]<--r_h){
                            complete=false;
                            curr_ht=curr_ht-(r_h-h[j]);
                            goto outer;
                        }
                    }
                }
                for( j=0; j<n; j++){
                    if((j-i)>=curr_ht)
                        cost+=h[j];
                    else
                        cost+=(h[j]-(curr_ht-abs(j-i)));
                }
                if(cost<min_cost)
                    min_cost=cost;
           }
           cout<<min_cost<<endl;
        }
        return 0;
    }
     
