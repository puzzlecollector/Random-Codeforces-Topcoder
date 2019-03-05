def d(x):
    ret = 0
    while x > 0:
        ret += (x%10)
        x /= 10
    return ret
ans = 0
for a in range(1,100):
    for b in range(1,100):
        ans = max(ans,d(a**b))
print(ans)
