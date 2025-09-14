// class Solution {

//    private:

//    void solve(vector<int> &nums,vector<int> & ans,vector<int> & currsum,int index,int sum,int &bestsum,int k){

//       if(currsum.size()>k) return;

   



//       if(currsum.size() == k){

//         if(sum>bestsum){

//             bestsum = sum;
//             ans = currsum;
//         }

//       return;

//       }

//       if(index >= nums.size()) return;

//    currsum.push_back(nums[index]);


//    // include.

//    solve(nums,ans,currsum,index + 1,sum + nums[index],bestsum,k);

//    currsum.pop_back();

//    // exclude

//    solve(nums,ans,currsum,index + 1,sum,bestsum,k);



//    }



// public:
//     vector<int> maxSubsequence(vector<int>& nums, int k) {
//          // using the brute force solution.

//          vector<int> ans,currsum;

//         int bestsum  = INT_MIN;
//          solve(nums,ans,currsum,0,0,bestsum,k);


//          return  ans; 




//     }
// };


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++) {
            arr.push_back({nums[i], i});
        }


        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

       
        arr.resize(k);

        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });

     
        vector<int> ans;
        for(auto &p : arr) {
            ans.push_back(p.first);
        }

        return ans;
    }
};