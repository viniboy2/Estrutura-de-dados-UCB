#include <stdio.h>
#include <stdlib.h>


typedef struct {
    double x;
    double y;
} Point;


double calculateArea(Point *points, int numVertices) {
    double area = 0.0;
    int i, j;

    for (i = 0; i < numVertices; i++) {
        j = (i + 1) % numVertices;
        area += (points[i].x * points[j].y - points[j].x * points[i].y);
    }

    area = area / 2.0;

    return (area < 0 ? -area : area); 
}

int main() {
    FILE *file;
    int numVertices, i;
    Point *points;

   
    file = fopen("poligono.txt", "r");
 if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    
    fscanf(file, "%d", &numVertices);

    
    points = (Point *)malloc(numVertices * sizeof(Point));

    if (points == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    for (i = 0; i < numVertices; i++) {
        fscanf(file, "%lf %lf", &points[i].x, &points[i].y);
    }

    // Fecha o arquivo
    fclose(file);

    // Calcula a área do polígono
    double area = calculateArea(points, numVertices);

    // Exibe a área do polígono
    printf("A área do polígono é %.2lf\n", area);

    // Libera a memória alocada
    free(points);

    return 0;
}

