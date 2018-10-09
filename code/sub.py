n = int(input())
ar = []
bestvals = []
best_stored = []
for x in range(n):
  ar.append(int(input()))
  best_stored.append(0)

best_stored[0] = 1

for i in range(n):
  maxval = 1
  for j in range(i):
    if ar[i] % ar[j] == 0:
      maxval = max(maxval,(best_stored[j])+1)
  best_stored[i] = maxval

print(max(best_stored))
