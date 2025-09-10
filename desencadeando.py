print(-3%10)
exit()

t = int(input())
acu=0 
answer = 0
a = [*map(int,input().split())]
out = [*map(int,input().split())]
for i in range(t-1,-1,-1):
    a[i] = (a[i]-acu)%10
    if a[i] == out[i]:
        continue
    up = (a[i]-out[i])%10
    down = (out[i]-a[i])%10
    x = min(up, down)
    if x == up:
        acu += up
    else: acu -= down
    answer += abs(min(up, down))
print(answer)