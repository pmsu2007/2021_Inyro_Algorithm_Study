def select(arr):
    for i in range(1,len(arr)):
        wow = i
        for j in range(i,0,-1):
            print("debug",wow,arr[wow],j-1,arr[j-1])
            if arr[wow] > arr[j-1]: 
                arr[wow], arr[j-1] = arr[j-1], arr[wow] 
                wow -= 1
                

arrarr = [7,5,3,9,4,6,2,8,6,3,1,8]
select(arrarr)
print(arrarr)
