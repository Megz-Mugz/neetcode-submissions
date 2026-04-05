class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        
        # build adjacency list
        adj_list = defaultdict(list)
        for v1, v2 in edges:
            adj_list[v1].append(v2)
            adj_list[v2].append(v1)


        # perform dfs
        visited = set()
        components = 0

        def perform_dfs(vertex):
            if vertex in visited: return

            visited.add(vertex)

            neighbors = adj_list[vertex]
            for neighbor in neighbors:
                perform_dfs(neighbor)

        for vertex in range(n):
            if vertex not in visited:
                components += 1
                perform_dfs(vertex)


        return components