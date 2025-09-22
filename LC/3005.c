int maxFrequencyElements(int* nums, int numsSize) {
    int cnts[100] = {0};
    for (int i=0; i<numsSize; ++i) {
        cnts[nums[i]-1]++;
    }
    int max_cnt=0;
    for (int i=0; i<100; ++i) {
        if (max_cnt < cnts[i]) {
            max_cnt = cnts[i];
        }
    }
    int res = 0;
    for (int i=0; i<100; ++i) {
        if (cnts[i] == max_cnt) {
            res += max_cnt;
        }
    }
    return res;
}