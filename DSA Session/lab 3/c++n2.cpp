#include<bits/stdc++.h>

using namespace std;
int inord[1123456];
int arr[1123456];
int k=1;
void inorder(int n,int root){
	if(root<=n){
		inorder(n,root*2);
		inord[k++]=arr[root];
		inorder(n,(root*2+1));
	}else
		return ;
}
int search(int num,int n){
	for(int i=1;i<=n;i++){
		if(num==inord[i]){
			return i;
		}
	}
return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	k=1;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	inorder(n,1);
	sort(arr+1,arr+n+1);
	int swap=0;
	for(int i=1;i<=n;i++){
		if(arr[i]!=inord[i]){
			int correctPos=search(arr[i],n);
			inord[correctPos]=inord[i];
			inord[i]=arr[i];
			swap++;
		}
	}
	cout<<swap<<endl;
	}
	return 0;
}
