from random import randint

class UnionFind:

    ds = []
    rank = []

    def __init__(self, N):
        self.ds = [i for i in range(N)]
        self.rank = [0 for i in range(N)]

    def find(self, x):
        if self.ds[x] != x:
            self.ds[x] = self.find(self.ds[x])
        return self.ds[x]

    def union(self, x, y):
        rx = self.find(x)
        ry = self.find(y)

        if rx == ry:
            return
        elif self.rank[rx] == self.rank[ry]:
            self.ds[rx] = ry
            self.rank[ry] += 1
        elif self.rank[rx] < self.rank[ry]:
            self.ds[rx] = ry
        else:
            self.ds[ry] = rx

class TreeGenerator:

    N = 0

    def __init__(self, N):
        self.N = N

    def generate(self):
        N = self.N
        self.ds = [i for i in range(N)]
        components = UnionFind(N)
        edges = []
        for i in range(N-1):
            while True:
                a = randint(0, N-1)
                b = randint(0, N-1)

                if components.find(a) != components.find(b):
                    edges.append((a, b))
                    components.union(a, b)
                    break

                #print edges 
                #print a, " and ", b, " in same component"

        return edges

N = 10**5
min_component_size = 10000 # NB! Last component created might violate this one
max_component_size = 100000

edges = []
added = 0
while added < N:
    size = randint(min(min_component_size, N-added),
            min(max_component_size, N-added))

    new_edges = TreeGenerator(size).generate()
    edges = edges + [(a+added, b+added) for (a,b) in new_edges]
    added += size

print N, len(edges)
for e in edges:
    print e[0], e[1]




