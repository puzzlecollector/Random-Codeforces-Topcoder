def d(x):
    ret = 0
    if x == 0: return 1
    while x > 0:
        ret += 1
        x /= 10
    return ret
def main():
    a = [0 for x in range(1005)] #numerator
    b = [0 for x in range(1005)] #denominator
    a[1] = 3
    a[2] = 7
    b[1] = 2
    b[2] = 5
    cnt = 0
    for i in range(3,1001):
        a[i] = 2*a[i-1]+a[i-2]
        b[i] = 2*b[i-1]+b[i-2]
        if d(a[i]) > d(b[i]):
            cnt += 1
    print(cnt)
if __name__ == "__main__":
    main() 
