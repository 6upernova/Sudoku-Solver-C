#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define COLUMNAS 9
#define FILAS 9

void printSudoku(int sudoku[FILAS][COLUMNAS]);
char *readfile(const char *filename);
void parseGridToArray(char *cadena, int sudoku[FILAS][COLUMNAS]);
int isValid(int sudoku[FILAS][COLUMNAS], int row, int col, int num);
int encontrarSolucion(int sudoku[FILAS][COLUMNAS], int col, int row);

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Es necesario pasar un archivo .txt con un sudoku");
    return 1;
  }

  int sudoku[FILAS][COLUMNAS];
  char *fileArr = readfile(argv[1]);
  parseGridToArray(fileArr, sudoku);

  printf("Sudoku unsolved :\n");
  printSudoku(sudoku);

  printf("Sudoku solved: \n");
  encontrarSolucion(sudoku, 0, 0);
  printSudoku(sudoku);
  return 0;
}

void parseGridToArray(char *cadena, int sudoku[FILAS][COLUMNAS]) {
  int arrCount = 0;
  for (int i = 0; i < FILAS; i++) {
    for (int j = 0; j < COLUMNAS; j++) {
      if (cadena[arrCount] == '\r') {
        arrCount++;
      }
      sudoku[i][j] = cadena[arrCount] - '0';
      arrCount++;
    }
    arrCount++;
  }
}

char *readfile(const char *filename) {
  if (!filename)
    return fprintf(stderr, "Error: @filename es NULL.\n"), NULL;
  /* Verificamos si el archivo existe y no está vacio, tambien si no es un
   * directorio. */
  struct stat s;
  if ((-1 == stat(filename, &s)) || S_ISDIR(s.st_mode) || !s.st_size)
    return fprintf(stderr, "Error: Archivo no existe o es un directorio.\n"),
           NULL;

  FILE *in = fopen(filename, "rb"); /* Abrimos el archivo para leer. */
  if (!in)
    return fprintf(stderr, "Error: No se pudo abrir el archivo.\n"), NULL;

  /* Colocamos el tamaño del archivo + 1 byte (vacio) */
  char *out = calloc(1, s.st_size + 1);
  if (!out) {
    fprintf(stderr,
            "Error: No se pudo pedir memoria para el contenido del archivo.\n");
    fclose(in);
    return NULL;
  }

  /* Luego leemos el archivo hasta el final y obtenemos una cadena con todo el
   * contenido. */
  (void)fread(out, s.st_size, 1, in);
  return out;
}

void printSudoku(int sudoku[FILAS][COLUMNAS]) {
  for (int i = 0; i < FILAS; i++) {
    // Print horizontal separator for 3x3 grids
    if (i % 3 == 0 && i != 0) {
      printf("------+------+------+\n");
    }

    for (int j = 0; j < COLUMNAS; j++) {
      // Print vertical separator for 3x3 grids
      if ((j % 3 == 0 && j != 0)) {
        printf("| ");
      }

      // Print the number with a space
      if (sudoku[i][j] == 0) {
        printf(". "); // Print a dot for empty cells
      } else {
        printf("%d ", sudoku[i][j]);
      }
    }
    printf("\n");
  }
}

int isValid(int sudoku[FILAS][COLUMNAS], int row, int col, int num) {
  int toret = 1;

  // Check if the num is in the row
  for (int i = 0; i < COLUMNAS && toret; i++) {
    if (sudoku[row][i] == num) {
      toret = 0;
    }
  }
  // Check if the num is in the column
  for (int j = 0; j < FILAS && toret; j++) {
    if (sudoku[j][col] == num) {
      toret = 0;
    }
  }

  // Check if the num is in the 3x3 square
  int startRow = row - (row % 3);
  int startCol = col - (col % 3);

  for (int n = 0; n < 3 && toret; n++) {
    for (int m = 0; m < 3 && toret; m++) {
      if (sudoku[startRow + n][startCol + m] == num) {
        toret = 0;
      }
    }
  }

  return toret;
}

int encontrarSolucion(int sudoku[FILAS][COLUMNAS], int col, int row) {

  // Caso base
  if (col == 9 && row == 8) {
    return 1;
  }

  // Si se llega al final de la FILA
  if (col == 9) {
    row++;
    col = 0;
  }

  // Si la celda no tiene 0
  if (sudoku[row][col] > 0) {
    return encontrarSolucion(sudoku, col + 1, row);
  }

  // Para todo 0 en la matriz:
  for (int i = 1; i <= 9; i++) {
    if (isValid(sudoku, row, col, i) == 1) {
      sudoku[row][col] = i;
      if (encontrarSolucion(sudoku, col + 1, row) == 1) {
        return 1;
      }
      sudoku[row][col] = 0;
    }
  }

  return 0;
}
