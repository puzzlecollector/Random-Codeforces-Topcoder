a = "" 
i = 1 
while len(a) <= 1000000: 
	a += str(i)
	i += 1 
j = 1 
ans = 1 
while j <= 1000000: 
	ans *= int(a[j-1]) 
	j *= 10 
print ans 
