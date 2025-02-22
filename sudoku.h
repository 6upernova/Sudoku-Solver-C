#include <stdio.h>
#include <stdblib.h>
#include <sudoku.h>

#define COLUMNAS = 9;
#define FILAS = 9;

int main(int argc, char* argv[]){

	if (argc != 1){
		printf("Es necesario pasar un archivo .txt con un sudoku);
		return 1;
	}

	int sudoku[FILAS][COLUMNAS];
	parseGridToArray(readfile(argv[0]),sudoku);
	printSudoku(sudoku);
	return 0;
}

void parseGridToArray(char* cadena,int sudoku[FILAS][COLUMNAS]){
	int arrCount = 0;
	for(int i = 0; i < FILAS; i++){
		for(int j= 0; j< COLUMNAS; j++){
			sudoku[i][j] = cadena[arrCount];
			arrCount++;
		}

	}
	
}

char *readfile(const char *filename) {
  if (!filename)
    return fprintf(stderr, "Error: @filename es NULL.\n"), NULL;
  /* Verificamos si el archivo existe y no está vacio, tambien si no es un directorio. */
  struct stat s;
  if ((-1 == stat(filename, &s)) || S_ISDIR(s.st_mode) || !s.st_size)
    return fprintf(stderr, "Error: Archivo no existe o es un directorio.\n"), NULL;

  FILE *in = fopen(filename, "rb"); /* Abrimos el archivo para leer. */
  if (!in)
    return fprintf(stderr, "Error: No se pudo abrir el archivo.\n"), NULL;

  /* Colocamos el tamaño del archivo + 1 byte (vacio) */
  char *out = calloc(1, s.st_size + 1);
  if (!out) {
    fprintf(stderr, "Error: No se pudo pedir memoria para el contenido del archivo.\n");
    fclose(in);
    return NULL;
  }

  /* Luego leemos el archivo hasta el final y obtenemos una cadena con todo el contenido. */
  (void)fread(out, s.st_size, 1, in);
  return out;
}


void printSudoku(int sudoku[FILAS][COLUMNAS]){
	for(int i = 0; i<FILAS; i++){
		printf("-------- --------- --------");

		for(int j = 0; j<COLUMNAS; j++){
			printf("%d",sudoku[i][j];
		}
		printf("\n");
	}

