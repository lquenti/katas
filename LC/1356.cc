#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), [](const auto orig_a, const auto orig_b){
            int n_a{0}, n_b{0}, a{orig_a}, b{orig_b};
            while (a) {
                n_a += a&1; a>>=1;
            }
            while (b) {
                n_b += b&1; b>>=1;
            }
	    //std::cout << "duck (" << a << ", " << n_a << ") (" << b << ", " << n_b << ")" << std::endl;
            if (n_a==n_b) {
                return orig_a<orig_b;
            }
            else {
                return n_a<n_b;
            }

        });
        return arr;
    }
};
