from collections import deque

def is_bipartite(graph):
    # Inicializa uma lista de cores com -1 (significa que o nó não foi colorido)
    n = len(graph)
    cor = [-1] * n

    for inicio in range(n):
        if cor[inicio] == -1:
            fila = deque([inicio])
            cor[inicio] = 0

            while fila:
                no = fila.popleft()

                for vizinho in graph[no]:
                    if cor[vizinho] == -1:
                        cor[vizinho] = 1 - cor[no]
                        fila.append(vizinho)
                    
                    elif cor[vizinho] == cor[no]:
                        return False
    return True

# Se quiser testar
graph1 = [[1,2,3],[0,2],[0,1,3],[0,2]];
graph2 = [[1,3],[0,2],[1,3],[0,2]];

print("Exemplo 1:", "verdadeiro" if is_bipartite(graph1) else "falso")
print("Exemplo 2:", "verdadeiro" if is_bipartite(graph2) else "falso")