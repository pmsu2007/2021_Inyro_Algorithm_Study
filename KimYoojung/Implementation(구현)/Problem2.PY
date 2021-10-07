check3 = 0
list3 = []
for i in range(60):
    s = str(i)
    for j in s:
        if j == "3":
            print(s)
            check3 +=1
            list3.append(int(s))
            break
print(check3)
print(list3)
hour3Check = 0
hour3Check += (60-15) * 15
hour3Check += 15*60
print(hour3Check) 

request = int(input())
endNum = 0
for i in range(request + 1):
    if i in list3:  endNum += 60*60
    else:  endNum += hour3Check

print(endNum)
    