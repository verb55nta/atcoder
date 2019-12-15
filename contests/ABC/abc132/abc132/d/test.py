mod = 1000000007
nn,kk = map(int, raw_input().split())

factorial = [1]
for n in xrange(1, 2002):
    factorial.append(factorial[n-1]*n%mod)

def power(x, y):
    if   y == 0     : return 1
    elif y == 1     : return x % mod
    elif y % 2 == 0 : return power(x, y/2)**2 % mod
    else            : return power(x, y/2)**2 * x % mod

inverseFactorial = [0] * 2002
inverseFactorial[2002-1] = power(factorial[2002-1], mod-2)
for n in xrange(2002-2, -1, -1):
    inverseFactorial[n] = inverseFactorial[n+1] * (n+1) % mod

def combi(n, m):
    return factorial[n] * inverseFactorial[m] * inverseFactorial[n-m] % mod

print(factorial[2001])
print(power(factorial[2001],mod-2))
print inverseFactorial[0]
print inverseFactorial[1]
print inverseFactorial[2]

for i in range(1,kk+1):
    if(i-1<=nn-kk):
        print(combi(nn-kk+1,i)*combi(kk-1,i-1)%mod)
    else:
        print(0)