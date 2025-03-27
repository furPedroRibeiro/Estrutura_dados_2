#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Exercícios sobre recursividade
    //Espaço destinado a primeira função -> soma de números naturais
    puts("---- FUNCAO SOMAR NATURAIS ----");
    int number;
    puts("\nDigite um numero: ");
    scanf("%d", &number);
    int result_soma_naturais = soma_naturais(number);

    printf("\nSoma dos naturais ate %d: %d", number, result_soma_naturais);

    //Espaço destinado a segunda função -> pixels da imagem representada pela matriz
    puts("\n\n\n---- FUNCAO CONVERTER PIXELS DA IMAGEM ----");
    int **m;
    int n_rows;
    int n_cols;
    puts("\n\nQtd. linhas da matriz:");
    scanf("%i", &n_rows);
    puts("Qtd. colunas da matriz:");
    scanf("%i", &n_cols);

    // //criando memória para as linhas da matriz
    m = (int **)calloc(n_rows, sizeof(int *));

    for(int i = 0; i < n_rows; i++){
        m[i] = (int *)calloc(n_cols, sizeof(int));
    }

    int **end_rows = m;
    int *end_cols = *end_rows;

    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_cols; j++){
            printf("\nDigite o conteudo na posicao[%i][%i]: ", i+1, j+1);
            scanf("%d", &end_cols[j]);
        }
        end_rows++;
        end_cols = *end_rows;
    }

    end_rows = m;
    end_cols = *end_rows;

    puts("\n-- Matriz antes:");

    for(int i = 0; i < n_rows; i++){
        printf("\n|");
        for(int j = 0; j < n_cols; j++){
            printf("%d ", end_cols[j]);
        }
        end_rows++;
        end_cols = *end_rows;
        printf("|");
    }

    int count_line = 1; //contador de linhas para a função recursiva
    pixels_imagem(m, n_rows, n_cols, count_line);

    end_rows = m;
    end_cols = *end_rows;

    puts("\n-- Matriz resultante:");

    for(int i = 0; i < n_rows; i++){
        printf("\n|");
        for(int j = 0; j < n_cols; j++){
            printf("%d ", end_cols[j]);
        }
        end_rows++;
        end_cols = *end_rows;
        printf("|");
    }

    //Espaço destinado a terceira função -> intercalar elementos de um vetor
    puts("\n\n\n---- FUNCAO INTERCALAR ELEMENTOS DO VETOR ----");

    puts("Testando submodule");

    int size_vec_1, size_vec_2;
    int *v1, *v2;

    printf("\n Digite o tamanho do vetor 1: ");
    scanf("%d", &size_vec_1);
    v1 = (int*)calloc(size_vec_1, sizeof(int));

    printf("\n Digite o tamanho do vetor 2: ");
    scanf("%d", &size_vec_2);
    v2 = (int*)calloc(size_vec_2, sizeof(int));

    for(int i = 0; i < size_vec_1; i++){
        printf("\nDigite o elemento [%d] do vetor 1: ", i);
        scanf("%d", &v1[i]);
    }
    for(int i = 0; i < size_vec_2; i++){
        printf("\nDigite o elemento [%d] do vetor 2: ", i);
        scanf("%d", &v2[i]);
    }


    int size_vec_3 = size_vec_1 + size_vec_2;
    int *v3 = (int *)calloc(size_vec_3, sizeof(int));

    int aux = intercalar_elementos(v1, v2, v3, size_vec_1-1, size_vec_2-1, size_vec_3-1);

    //Mostrar vetor intercalado
    puts("\nVetor com valores intercalados:");
    printf("[");
    for(int i = 0; i < size_vec_3; i++){
        printf(" %d", v3[i]);
    }
    printf("]");

    //show_complexidade();

    return 0;
}

int count_operations_soma_naturais = 0;

int soma_naturais(int n){
    int result = 0;
    count_operations_soma_naturais++;
    if(n>1){
        result = soma_naturais(n-1);
        //condicional do if
        count_operations_soma_naturais++;
        //atribuição de result e n-1
        count_operations_soma_naturais = count_operations_soma_naturais + 2;
    } else{
        //operação do return
        count_operations_soma_naturais = count_operations_soma_naturais + 2;
        return result + n;
    }

    //operação do return
    count_operations_soma_naturais = count_operations_soma_naturais + 2;
    return result + n;
}

void pixels_imagem(int** m, const int rows, const int cols, int count_line){
    int **matriz = m;
    int **end_rows_after = m;
    int *end_cols_after = *end_rows_after;

    if(count_line < rows){
        matriz++;
        count_line++;
        pixels_imagem(matriz, rows, cols, count_line);
    }
    for(int i = 0; i < cols; i++){
        end_cols_after[i] = 255 - end_cols_after[i];
    }
}

int intercalar_elementos(int *v1, int *v2, int *v3, int size_vec_1, int size_vec_2, int size_vec_3){
    if((size_vec_1-size_vec_2) != 0 && (size_vec_1-size_vec_2) > 0){
        size_vec_3 = intercalar_elementos(v1, v2, v3, (size_vec_1-1), size_vec_2, size_vec_3);
        v3[size_vec_3] = v1[size_vec_1];
        return size_vec_3+1;
    } else if((size_vec_2-size_vec_1) != 0 && (size_vec_2-size_vec_1) > 0){
        size_vec_3 = intercalar_elementos(v1, v2, v3, size_vec_1, size_vec_2-1, size_vec_3);
        v3[size_vec_3] = v2[size_vec_2];
        return size_vec_3+1;
    } else if(size_vec_1 != 0){
        size_vec_3 = intercalar_elementos(v1, v2, v3, (size_vec_1-1), (size_vec_2-1), size_vec_3);
        v3[size_vec_3] = v1[size_vec_1];
        v3[size_vec_3+1] = v2[size_vec_2];
        return size_vec_3 + 2;
    } else if(size_vec_1 == 0){
        size_vec_3 = 0;
        v3[size_vec_3] = v1[size_vec_1];
        v3[size_vec_3+1] = v2[size_vec_2];
        return 2;
    }
    return 0;
}

void show_complexidade(){
    printf("\nOperacoes soma de inteiros: %d" ,count_operations_soma_naturais);
}
