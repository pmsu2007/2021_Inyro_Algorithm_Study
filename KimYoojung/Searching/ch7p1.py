'''
n = 5
haves = [1,2,3,4,5]
m = 3
wants = [2,5,7]
'''

n = int(input())
haves = list(map(int, input().split(" ")))
m = int(input())
wants = list(map(int, input().split(" ")))

haves.sort()

def bin_search(haves, want, start, end):
    if start > end:
        return False
    mid = (start + end) // 2
    if haves[mid] == want:
        return True
    elif want < haves[mid]:
        return bin_search(haves, want, start, mid-1)
    else: 
        return bin_search(haves, want, mid+1, end)

for i in wants:
    if (bin_search(haves, i, 0, n-1)):
        print("yes",end=" ")
    else: print("no",end=" ")
