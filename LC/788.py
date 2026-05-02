
def is_valid(i: int) -> bool:
    has_changed_digit = False
    while i != 0:
        digit = i%10
        i //= 10
        if digit in (0,1,8):
            continue
        elif digit in (2,5,6,9):
            has_changed_digit = True
        else:
            return False
    return has_changed_digit

cpp_prefix = """
#include <array>
auto xs = std::to_array({0,
"""
cpp_suffix = """
});
class Solution {
public:
    int rotatedDigits(int n) {
        return xs[n];
    }
};
"""

print(cpp_prefix)
cnt=0
for i in range(1,10002):
    if is_valid(i):
        cnt+=1
    if i%100==0:
        print(cnt)
    else:
        print(cnt, end="")
    if i != 10001:
        print(",", end="")
print(cpp_suffix)
