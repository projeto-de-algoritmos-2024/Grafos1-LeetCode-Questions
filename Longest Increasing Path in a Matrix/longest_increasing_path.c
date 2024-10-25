#include <stdio.h>
#include <stdlib.h>

int dfs(int** matrix, int m, int n, int row, int col, int** cache) {
    // Se já calculamos o caminho crescente para essa célula, retorne o valor armazenado

    if (cache[row][col] != 0) {
        return cache[row][col];
    }
    
    // Quatro direções possíveis: esquerda, direita, para cima e para baixo
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int maxPath = 1;    // O caminho mínimo será de comprimento 1 (apenas a célula atual)
    
    for (int i = 0; i <4; ++i) {
        int newRow = row + directions[i][0];
        int newCol= col + directions[i][1];
        
        // Verifica se estamos dentro dos limites e se a célula vizinha tem um valor maior
        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && matrix[newRow][newCol] > matrix[row][col]) {
            int pathLength = 1 + dfs(matrix, m, n, newRow, newCol, cache);
            maxPath= (pathLength > maxPath) ? pathLength : maxPath;
        }
    }
    
    // Armazena o resultado na cache
    cache[row][col] = maxPath;
    return maxPath;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return 0;
    
    int m =matrixSize;
    int n =matrixColSize[0];
    
    // Matriz para armazenar os resultados de cada célula
    int** cache = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        cache[i] = (int*)calloc(n, sizeof(int));
    }
    
    int maxPath = 0;
    

    // Realiza DFS a partir de cada célula
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int pathLength = dfs(matrix, m, n, i, j, cache);
            maxPath = (pathLength > maxPath) ? pathLength :maxPath;
        }
    }
    
    // Libera a memória alocada para a cache
    for (int i = 0; i < m; ++i) {
        free(cache[i]);
    }

    
    free(cache);
    
    return maxPath;
}
