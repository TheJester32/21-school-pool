#include <stdio.h>
#include <stdlib.h>

void freeMatrix(int **matrix, int rows);
int allocateStaticMatrix(int rows, int cols);
int **allocateDynamicMatrix(int rows, int cols);
void freeMatrix(int **matrix, int rows);
void inputStaticMatrix(int rows, int cols);
int inputMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);

int main() {
  int choice;
  int rows, cols;
  int **matrix;

  scanf("%d", &choice);
  if (choice > 4 || choice == 0) {
    printf("n/a");
    return 0;
  }
  scanf("%d %d", &rows, &cols);
  if (rows > 100 || rows <= 0 || cols <= 0) {
    printf("n/a");
    return 0;
  }

  switch (choice) {
  case 1:
    allocateStaticMatrix(rows, cols);
    break;
  case 2:
    matrix = allocateDynamicMatrix(rows, cols);
    break;
  case 3:
    matrix = allocateDynamicMatrix(cols, rows);
    break;
  case 4:
    matrix = allocateDynamicMatrix(rows, cols);
    break;
  default:
    printf("n/a");
    return 0;
  }

  if (choice != 1) {
    if (inputMatrix(matrix, rows, cols) != 0) {
      printf("n/a");
      return 0;
    }
    printMatrix(matrix, rows, cols);
    freeMatrix(matrix, rows);
  }

  if (matrix == NULL) {
    printf("n/a");
    return 0;
  }
}

int allocateStaticMatrix(int rows, int cols) {
  int check = 0;
  int matrix[100][100];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (scanf("%d", &matrix[i][j]) == 1) {
        matrix[i][j] = matrix[i][j];
      } else {
        printf("n/a");
        check = 1;
        break;
      }
    }
    if (check == 1) {
      break;
    }
  }
  if (check == 0) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        printf("%d", matrix[i][j]);
        if (j != cols - 1) {
          printf(" ");
        }
      }
      if (i != rows - 1) {
        printf("\n");
      }
    }
  }
  return check;
}

int **allocateDynamicMatrix(int rows, int cols) {
  int **matrix = malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(cols * sizeof(int));
  }
  return matrix;
}

void freeMatrix(int **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void inputStaticMatrix(int rows, int cols) {
  int matrix[rows][cols];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

int inputMatrix(int **matrix, int rows, int cols) {
  int check = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (scanf("%d", &matrix[i][j]) == 1) {
        matrix[i][j] = matrix[i][j];
      } else {
        check = 1;
        break;
      }
    }
    if (check == 1) {
      break;
    }
  }
  return check;
}

void printMatrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d", matrix[i][j]);
      if (j != cols - 1) {
        printf(" ");
      }
    }
    if (i != rows - 1) {
      printf("\n");
    }
  }
}