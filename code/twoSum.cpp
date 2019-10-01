#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

pair<int, int> twoSum(vector<int>&nums, int target){
    unordered_map<int, int> umap;
    int tmp;
    for(int i = 0;i < nums.size();i++){
        tmp = target - nums[i];
        if(umap.find(tmp) != tmp.end())
        {
            pair<int, int> res(make_pair(umap.find(tmp), i));
            return res;
        }
        umap[nums[i]] = i;
    }
}
int main(){
    int n, target;
    cin >> target >> n;
    vector<int> nums(n);
    for(auto &x : nums)
    cin >> x;
    pair<int, int> res(twoSum(nums, target));
    cout << res.first << ' ' << res.second << endl;
    return 0;
}