from functools import reduce
a= [120,34,99,87,77,60]
print(reduce(lambda x,y:x+x,a))
print(reduce(lambda x,y:str(x)+str(y),a))

a=[1,2,3,4,5]
print(filter(lambda x:x%2==0,a))

a=[1,2,3,4,5]
print(filter(lambda x:x>3,a))

a=["Vinod","Ramesh","Sejal","Shekhar","Sainath","Sahil"]
print(list(filter(lambda x:x[0]=='S',a)))
a=[1,2,3,4,5]
print(list(filter(lambda x:x%2==0,a)))

a=[1,2,3,4,5]
print(list(filter(lambda x:x>3,a)))










a=lambda x:"even" if x%2==0 else "odd"
print(list(map(a,[1,2,3,4,5])))

a=lambda x:x-1
print(list(map(a,[1,2,3,4,5])))

a=lambda x:x*x
print(list(map(a,(1,2,3,4,5))))









c=lambda x: "Divisible by 5" if x%5==0 else "Not divisible by 5"
print(c(14))

c=lambda x: "Leap Year" if x%4==0 and x%100==0 else "Non leap year"
print(c(1900))

c=lambda x: "Even" if x%2==0 else "odd"
print(c(6))



# we can use all four types of parameter with lambda
do = lambda x, y, *z, **a: x + y +z[0][0]+ a.get('b')
result = do(1, 3, (10, 30), a=2, b=4)
print(result)



do = lambda x, y, *z: x + y + z[0][0]
print(do(1, 3, (10, 30)))


do = lambda x,z,y:(x+y,y+z)
print(do(x=10,y=20,z=30))

do = lambda x,y,z=9:(x+y,y+z)
print(do(10,20))