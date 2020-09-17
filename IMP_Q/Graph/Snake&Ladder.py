from collections import deque

def quickestWayUp(n,m,,sp,ep):
  paths = {}
  for s,d in ladders + snakes:
    paths[s] = d

  q = deque([(sp, 0)])
  visited = set()
  while q:
    sq, rolls = q.popleft()
    if ep == sq:
      return rolls

    visited.add(sq)
    for i in range(1, m+1):
      next = sq + i
      if next in visited or next > n+1: continue

      q.append((next in paths and paths[next] or next, rolls + 1))
  return -1