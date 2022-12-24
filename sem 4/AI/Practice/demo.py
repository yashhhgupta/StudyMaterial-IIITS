#list
l =[]
l.append(12)
l.append(1)
l.append(11)
l.append(111)
l.append(121)
l.append(18)
print(l)
l.sort()
print(l)
print(l[-1])
#-1 for last element of list
List=[12,1,11,111,121,18,22,33,44,55,66,77,88,99]
print(List)
print(List[2:6])
print(List[2:])
print(List[:6])
print('length=',len(l))
#tuple
tu=(12,32,43,53,23)
print(type(tu))
print(tu)
tu1 =sorted(tu)
print(tu1)

#..................
#...........
#...........
#...........
#...........
str= ['I','am','Yash']
print(str)
str= "saLLY hhJJJ bbDDD"
st=str.title()
print(st)
n=10
if(n==9):
    print('n is 9')
else:
    print('n is not 9')
n=[11,22,33,44,55,66,77,88,99]
for i in range(0,12,2):
    print(i)
for i in range(len(n)):
    print(i,n[i])

# while(condition):
#     statement
index = len(n)
while(index>0):
    print(index,n[index-1])
    index=index-1