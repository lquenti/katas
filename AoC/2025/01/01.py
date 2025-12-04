start=50
cnt=0
with open("01.input", "r") as fp:
    for line in fp:
        sign = 1 if line[0]=="R" else -1
        num = int(line[1:])
        start += sign*num
        start %= 100
        if start==0:
            cnt+=1
print(cnt)

start=50
cnt=0
with open("01.input", "r") as fp:
    for line in fp:
        if line[0] == "R":
            start+=int(line[1:])
            cnt+=start//100
            start%=100
        else:
            cnt+=(int(line[1:])+(-start%100))//100
            start=(start-int(line[1:]))%100
print(cnt)
