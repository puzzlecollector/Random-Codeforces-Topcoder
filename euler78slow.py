MAXN = 100005
mod = 1000000
cache = [] # cache array
for i in range(0,MAXN):
    cache.append([])
    for j in range(0,MAXN):
        cache[i].append(-1)
def solve(n,previous):
    if n == 0:
        return 1
    if cache[n][previous] != -1:
        return cache[n][previous]
    cache[n][previous] = 0
    for i in range(previous,0,-1):
        if n-i >= 0:
            cache[n][previous] += solve(n-i,i)
    return cache[n][previous]

if __name__== "__main__":
    for i in range(1,100000):
        if solve(i,i)%mod == 0:
            print i
            break
