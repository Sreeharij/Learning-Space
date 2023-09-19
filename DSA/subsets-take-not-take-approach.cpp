//GENERATING SUBSETS CLEAN IMPLEMENTATION USING TAKE/NOT TAKE APPROACH
#include <iostream>
#include <vector>

using namespace std;

void print_powerset(vector<vector<int>>& powerset){
    for(auto subsequence: powerset){
        for(auto value: subsequence){
            cout<<value<<" ";
        }cout<<endl;
    }
    cout<<"\n\n";
}

void generate_powerset(vector<vector<int>> &powerset,vector<int> &subset,int arr[],int n){
    if(n == 0){
        powerset.push_back(subset);
        return;
    }
    subset.push_back(arr[n-1]);
    generate_powerset(powerset,subset,arr,n-1);
    subset.pop_back();
    generate_powerset(powerset,subset,arr,n-1);
}

int main()
{
    int arr[] = {3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> subset;
    vector<vector<int>> powerset;
    generate_powerset(powerset,subset,arr,size);
    print_powerset(powerset);

    return 0;
}
