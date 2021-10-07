def p4(n, k, arra, arrb):
    arra.sort()
    arrb.sort()
    for i in range(k):
        if arra[i] >= arrb[n-1-i]: return
        else: arra[i], arrb[n-1-i] = arrb[n-1-i], arra[i]

n = 5
k = 3
arra = [1,2,5,4,3]
arrb = [5,5,6,6,5]
p4(n, k, arra, arrb)
print(arra)
print(arrb)
 
