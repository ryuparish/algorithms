
n = int(input())
ipt = input()
# Taking in the inputs and assigning them as integers by mapping them. (trying int(input) will try to make the entire read in line a single integer) 
a = list(map(int, ipt.split()))
ipt = input()
b = list(map(int, ipt.split()))

a.sort()
b.sort()
c = []
for i in range(n):
    c.append(a[i] * b[i])

print(sum(c))
        
