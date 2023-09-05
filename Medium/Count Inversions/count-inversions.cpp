//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    long long count;
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        count = 0;
        
        mergeSort(arr, 0 , N-1);
        return count;
        
    }
    
    void merge(long long v[],int l,int mid,int h)
{
    
    long long i=l,j=mid+1;
    vector<long long > vec;
    
    while(i<=mid && j<=h)
    {
        if(v[i]<=v[j])
        {
            vec.push_back(v[i]);
            i++;
        }
        else{
            count+=mid+1-i;
            vec.push_back(v[j]);
            j++;
        }
    }
    
    while(i<=mid)
    {
        vec.push_back(v[i]);
        i++;
    }
    while(j<=h)
    {
        vec.push_back(v[j]);
        j++;
    }
    
    
    for(int i=l;i<=h;i++)
    {
        v[i]=vec[i-l];
    }
}
    
    void mergeSort(long long arr[],int low,int high)
    {
        if(low<high)
        {
            long long mid=low+(high-low)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends