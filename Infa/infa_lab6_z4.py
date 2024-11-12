n=int(input())
x=n
for i in range(1,n+1):
    print(" "*(x-1), "#"*(i*2-1))
    x-=1
if n%2==0:
    print(" "*((n+4)//2), '#')
if n%2==1:
    print(" "*((n+3)//2), '#')
