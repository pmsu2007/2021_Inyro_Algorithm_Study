n = input()
half = len(n) // 2
left = 0
right = 0
for i in range(0,half):
    left += int(n[i])
for i in range(half,len(n)):
    right += int(n[i])
if left == right: print("LUCKY")
else: print("READY")