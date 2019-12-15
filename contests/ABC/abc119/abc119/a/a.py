s=input()
#print(s)
year,m,d=s.split('/')
year=int(year)
m=int(m)
d=int(d)

if( year > 2020 or (year==2019 and m > 4 )):
    print("TBD")
else:
    print("Heisei")
