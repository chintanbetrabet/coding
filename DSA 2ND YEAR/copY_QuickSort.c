#include <conio.h>
#include <string>

using namespace std;
void InputArray(int*,int);
void QuickSort(int *,int,int);
int partition(int *,int,int);
void swap(int *,int,int);
void printArr(int *,int Siz=11);

void main(){

    int siz;
    cout<<"Enter Array length   :   "; cin>>siz; 
    int *a=new int[siz];

    InputArray(a,siz);
    QuickSort(a,0,siz-1);
    int i=0,j=11;

    printArr(a,siz);
    system("pause");

}


void InputArray(int*a,int s){
    for(int i=0; i<s; i++){
        cout<<"ELement ["<<i<<"] =  "; cin>>a[i];
    }

}
void QuickSort(int *a,int start,int end){
    if(start<end){
        int pivot=partition(a,start,end);

        QuickSort(a,start,pivot);
        QuickSort(a,pivot+1,end);
    }


}
int partition(int *a,int start,int end){

    int currentPivotValue=a[start];
    int i=start-1, j=end+1;
    while(true){
        i++;
        while(i<j && a[i]<currentPivotValue){ i++; }
        j--;

        while(j>start && a[j]>currentPivotValue) {j--;}
        if(i<j) swap(a,i,j);        
        else return j;
    }


}
void swap(int *b,int i,int j){
    int t=b[i];
    b[i]=b[j];
    b[j]=t;



}
void printArr(int *a,int Siz){
    for(int i=0; i<Siz; i++) cout<<a[i]<<" "; 
}

