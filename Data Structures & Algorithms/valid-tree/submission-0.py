class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        
        # guard rail
        if n - 1 != len(edges): return False

        adjacency_list = defaultdict(list)
        for v1, v2 in edges:
            adjacency_list[v1].append(v2)
            adjacency_list[v2].append(v1)


        def detect_cycle(vertex, visited):

            queue = deque([(vertex, vertex)]) # focus vertex & parent
            visited.add(vertex)

            while queue:

                len_of_level = len(queue)

                for _ in range(len_of_level):
                    v, parent = queue.popleft()
                    for neighbor in adjacency_list[v]:
                        if parent == neighbor: continue
                        if neighbor in visited: 
                            return True
                        queue.append((neighbor, v))
                        visited.add(neighbor)

            return False


        for v in range(n):
            if detect_cycle(v, set()):
                return False

        return True