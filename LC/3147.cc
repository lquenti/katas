class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> psum(energy.size(), -1);
        for (int i=energy.size()-k; i<energy.size(); i++) {
            int curr_val{0};
            for (int j=i; j>=0; j-=k) {
                curr_val += energy[j];
                psum[j]=curr_val;
            }
        }
        return *std::max_element(psum.begin(), psum.end());
    }
};
