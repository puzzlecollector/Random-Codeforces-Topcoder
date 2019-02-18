def power(a,x):
    if x == 0: return 1
    if x == 1: return a
    return power(a,x/2)*power(a,x/2)*power(a,x%2)
sum = 0
for i in range(1,1001):
    sum += power(i,i)
print(sum%10000000000)
