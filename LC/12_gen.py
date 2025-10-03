PREFIX = """
#include<stdio.h>
char *arr[] = {
  0,
"""
SUFFIX = """
};
char* intToRoman(int num) {
  return arr[num];
}
"""

print(PREFIX)
for i in range(1, 4000):
    thos = i//1000
    huns = (i%1000)//100
    tens = (i%100)//10
    ones = i%10

    thos_s = 'M'*thos

    huns_s = ""
    if (huns == 4):
        huns_s = "CD"
    elif (huns == 9):
        huns_s = "CM"
    else:
        if (huns >= 5):
            huns_s += "D"
            huns -= 5
        huns_s += 'C'*huns

    tens_s = ""
    if (tens == 4):
        tens_s = "XL"
    elif (tens == 9):
        tens_s = "XC"
    else:
        if (tens >= 5):
            tens_s += "L"
            tens -= 5
        tens_s += 'X'*tens

    ones_s = ""
    if (ones == 4):
        ones_s = "IV"
    elif (ones == 9):
        ones_s = "IX"
    else:
        if (ones >= 5):
            ones_s += "V"
            ones -= 5
        ones_s += 'I'*ones

    print(f"\"{thos_s}{huns_s}{tens_s}{ones_s}\",", end="")
    if i % 100 == 0:
        print()

# to close array
print(0)

print(SUFFIX)
