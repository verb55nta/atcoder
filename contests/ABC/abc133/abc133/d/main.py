import numpy as np

#n= map(int, input().split())
n=input()

f=lambda x:int(x)

a=np.array(list(map(f,input().split())))

#print(n)
#print(a)



x=np.zeros( (len(a),len(a)) )

#print(x)
#print(x.shape)

for i in range( len(a) ):
    if(i== len(a)-1 ):
        x[i][0]=1
        x[i][i]=1
    else:
        x[i][i]=1  
        x[i][i+1]=1

#print(x)
#print(np.linalg.inv(x))
print(x)
inv=np.linalg.inv(x)

print(2*inv)

ans = 2 * np.dot( inv , a )

#print(ans)

for i in ans:
    print(int(i))