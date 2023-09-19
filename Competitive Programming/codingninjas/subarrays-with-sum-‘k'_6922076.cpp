//OPTISED SOLUTION USING SLIDING WINDOW CONCEPT
vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    vector<vector<int>> answer;
    vector<int> subarray;
    int length = a.size();
    int left = 0,right = 0;
    long long current_sum = a[0];
    
    while(right < length ){
        if(current_sum < k){
            right++;
            if(right < length){
                current_sum += a[right];
            }
        }
        else if(current_sum > k){
            current_sum -= a[left];
            left++;
        }
        else{
            subarray.clear();
            for(int i=left;i<=right;i++){
                subarray.push_back(a[i]);
            }
            answer.push_back(subarray);
            left++;
            right++;
            current_sum -= a[left-1];
            if(right < length){
                current_sum += a[right];
            }            
        }
    }
    return answer;
}