a, b, c, d, e, f, g, h = map(int, input().split())
l1 =((e-a)*(b-d)-(f-b)*(a-c))*((g-a)*(b-d)-(h-b)*(a-c))
l2=((a-e)*(f-h)-(b-f)*(e-g))*((c-e)*(f-h)-(d-f)*(e-g))
print(1 if l1 < 0 and l2 < 0 else 0)