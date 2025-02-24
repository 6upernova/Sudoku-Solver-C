#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#define COLUMNAS  9
#define FILAS  9

void printSudoku(int sudoku[FILAS][COLUMNAS]);
char *readfile(const char *filename);
void parseGridToArray(char* cadena,int sudoku[FILAS][COLUMNAS]);


int main(int argc, char* argv[]){

	if (argc != 2){
		printf("Es necesario pasar un archivo .txt con un sudoku");
		return 1;
	}

	int sudoku[FILAS][COLUMNAS];
	char* fileArr = readfile(argv[1]);
	printf("length of array %ld\n",strlen(fileArr));
	printf("array:%s\n",fileArr);
	parseGridToArray(fileArr,sudoku);
	printSudoku(sudoku);
  printf("1/3: %d", 1/3);
	return 0;
}

void parseGridToArray(char* cadena,int sudoku[FILAS][COLUMNAS]){
	int arrCount = 0;
	for(int i = 0; i < FILAS; i++){
		for(int j= 0; j< COLUMNAS; j++){
      if(cadena[arrCount] == '\r'){
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
		for(int j = 0; j<COLUMNAS; j++){
			printf("%d",sudoku[i][j]);
      printf("|");
        
        
		}
		printf("\n");
	}
}

int isValid(int sudoku[][], int row, int col, int num){

  int toret = 1;
  
  //Check if the num is in the row
  for(int i = 0; i< COLUMNAS && toret; i++){
    if(sudoku[row][i] = num){
      toret = 0;
    }
  }
  //Check if the num is in the column
  for(int j = 0; i< FILAS && toret; j++){
    if(sudoku[j][col] == num){
      toret 0;
    }
  }
  
  //Check if the num is in the 3x3 square
  
}  
