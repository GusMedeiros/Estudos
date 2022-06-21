#include <stdio.h>

int main (void) {
    int n=0, i=0, j;
    float numero, aux;
    FILE *fp, *arqbin ;

    fp = fopen ("numeros.txt", "r");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    while (fscanf(fp, "%f ", &numero) == 1) {
        n++;
    }

    fclose(fp);

    float *vetor_numeros = (float*)malloc(n*sizeof(float));
    if (vetor_numeros==NULL) {
        printf("Falta memoria\n");
        exit(1);
    }

    fp = fopen ("numeros.txt", "r");

    while (fscanf(fp, "%f ", &numero) == 1) {
        vetor_numeros[i]=numero;
        i++;
    }

    fclose(fp);

    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if (vetor_numeros[i] > vetor_numeros[j]){
                aux = vetor_numeros[i];
                vetor_numeros[i] = vetor_numeros[j];
                vetor_numeros[j] = aux;
            }
        }
    }

    arqbin = fopen("numeros.bin", "wb");
    if (arqbin == NULL) {
        printf("Erro na criacao do arquivo.\n");
        exit(0);
    }

    fwrite (&vetor_numeros[0], sizeof(float), n, arqbin);
    fclose(arqbin);


    for (i=0;i<n;i++){
        printf("%.2f ", vetor_numeros[i]);
    }

    return 0;
}
