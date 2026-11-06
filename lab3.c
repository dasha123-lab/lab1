#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_natural_string(const char *str) {
    if (str[0] == '\0' || str[0] == '0' || str[0] == '-') {
 return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int is_integer_string(const char *str) {
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
     start += 1;                                                                                                            }

    if (str[start] == '\0') {
 return 0;
    }

    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int is_float_string(const char *str) {
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
     start += 1;
    }

    if (str[start] == '\0') {
 return 0;
    }

    int dot_count = 0;
    int digit_count = 0;

    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dot_count++;
            if (dot_count > 1) {
                return 0;
            }
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            digit_count++;
        }
        else {
            return 0;
        }
    }

    if (digit_count == 0) {
        return 0;
    }

    return 1;
}

int main() {
    char *N_str = NULL;
    char *M_str = NULL;
    int M, N;

    while (1) {
        printf("Введите N: ");
        if (scanf("%ms", &N_str) != 1) {
            printf("Ошибка чтения.\n");
            free(N_str);
     continue;
        }
        if (is_natural_string(N_str)) {
         N = atoi(N_str);
     free(N_str);
     break;
        } else {
     free(N_str);
     printf("Число должно быть натуральным!\n")
        }
    }

    while (1) {
        printf("Введите M: ");
        if (scanf("%ms", &M_str) != 1) {
            printf("Ошибка чтения.\n");
            free(M_str);
            continue;
        }
        if (is_natural_string(M_str)) {
            M = atoi(M_str);
     free(M_str);
            break;
        } else {
     printf("Чиcло должно быть натуральным!\n");
     free(M_str);
 }
    }

    float *Matrix = malloc(M * N * sizeof(*Matrix));                                                                    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         char *element = NULL;
         float value;

         while (1) {
          printf("Введите элемент [%i][%i]: ", i, j);
          if (scanf("%ms", &element) != 1) {
                  printf("Ошибка чтения.\n");
                  free(element);
           continue;
          }
          if (is_float_string(element)) {
               value = atof(element);
           free(element);
           break;
          } else {
           free(element);
           printf("Некорректный ввод!\n");
          }
     }
        Matrix[i*M + j] = value;
    }
    }
float maxotr = 0.0;
int found = 0;
  for (int i = 0; i<N; i++) {
     for (int j = 0; j<M; j++) {
        if (i + j < N - 1) {
          if (Matrix[i*M + j] < 0) {
            if (!found || Matrix[i*M + j] > maxotr) {
            maxotr = Matrix[i*M + j];
            found = 1;
              }
           }
        }
     }
  }
  if (found == 1) {
   printf ("Наибольший отрицательный элемент над побочной диагональю: %.1f\n", maxotr);
  } else {
        printf ("Над побочной диагональю нет отрицательных элементов.\n");
    }
float a23 = 0.0;
   if (N >= 2 && M >= 3){
   a23 = Matrix[1*M + 2];
  }
    else {
    printf("Матрица меньше 2*3, элемент а23=0");
  }
  for (int j = 0; j < M; j++){
  float sum = 0.0;
    for (int i = 0; i < N; i++) {
    sum += Matrix[i*M + j];
  }
    float Sj = sin(sum + 3.0 * a23);
    printf("значение S для каждого столбца: \n");
    printf("S%d = %f\n", j + 1, Sj);
  }
    for (int i = 0; i < N; i ++) {
      for (int j = 0; j < M; j ++) {
printf("| %.1f |", Matrix[i*M + j]);
       }
       printf("\n");
    }
free(Matrix);
return 0;
}
