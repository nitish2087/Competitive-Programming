n=int(input())
for _ in range(n):
    s=input().split('.')
    s.reverse()
    print('.'.join(s))
