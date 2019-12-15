import fractions
import numpy as np
from functools import reduce

def gcd(*numbers):
    return reduce(fractions.gcd, numbers)

def gcd_list(numbers):
    return reduce(fractions.gcd, numbers)

def lcm_base(x, y):
    return (x * y) // math.gcd(x, y)

def lcm(*numbers):
    return reduce(lcm_base, numbers, 1)

def lcm_list(numbers):
    return reduce(lcm_base, numbers, 1)

n=int(input())

arr = np.array(list(map(int,input().split()))).astype(np.int)

ans=0

c=gcd_list(arr)


lc=lcm_list(arr)
#arr/=c


for i in range(n):
    ind = np.ones(n, dtype=bool)
    ind[i] = False
    #print(arr[ind])
    ans=max(ans,gcd_list(arr[ind]) )

print(ans)