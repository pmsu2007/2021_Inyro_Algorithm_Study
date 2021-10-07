def selectName(score, name):
    for i in range(1, len(score)):
        now = i
        for j in range(i,0,-1):

            if score[now] < score[j-1]:
                score[now], score[j-1] = score[j-1], score[now]
                name[now], name[j-1] = name[j-1], name[now]
                now -=1
name = ["a", "b", "c", "d", "e", "f"]
score = [56,75,94,31,5,68]
selectName(score,name)
print(name)
print(score)

# a = int(input())
# name = []
# score = []
# for i in range(a):
#     data = input().split(" ")
#     name.append(data[0])
#     score.append(int(data[1]))
# selectName(score,name)
# for i in name:
#     print(i,end=" ")

