l = [int(x) for x in input().split()]

if (1 in l or l.count(2) >= 2 or l.count(3) == 3 or sorted(l) == [2,4,4]):
  print ("YES")
else:
  print ("NO")