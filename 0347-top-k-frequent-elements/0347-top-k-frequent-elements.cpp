class Solution {
public:
// alone map wont work here;n note that <key, value> 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequencyMap;

    // Count the frequency of each element using a hashmap
    for (int num : nums) {
        frequencyMap[num]++;
    }

    // Create a bucket of vectors to store elements with the same frequency
    std::vector<std::vector<int>> bucket(nums.size() + 1); // Frequencies are at most nums.size()

    // Populate the bucket with elements based on their frequencies
    for (const auto& entry : frequencyMap) {
        bucket[entry.second].push_back(entry.first);
    }

    // Extract the top k frequent elements from the bucket
    std::vector<int> result;
    for (int i = bucket.size() - 1; i >= 0 && result.size() < k; --i) {
        result.insert(result.end(), bucket[i].begin(), bucket[i].end());
    }

    return result;
    }
};