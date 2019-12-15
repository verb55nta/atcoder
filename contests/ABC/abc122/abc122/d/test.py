n=int(input())

obj=[1,4,16,61,230]
n_obj=[0,0,0,3,26]

for i in range(5,201,1):
    #print(i)
    _no=obj[i-3]*3 + obj[i-4]*2 + n_obj[i-1]*4
    n_obj.append(_no)
    o=4**i - _no
    obj.append(o)
    #print(_no)
    #print(o)
print( "{}".format(obj[n] % 1000000007 ))
    