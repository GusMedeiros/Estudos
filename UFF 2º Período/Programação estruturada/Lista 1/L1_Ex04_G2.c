#include <stdio.h>
float calcmedia(float num1, float num2, float num3);

int main()
{
    float A, B, C, media;
    
    scanf("%f", &A);
    scanf("%f", &B);
    scanf("%f", &C);
    
    if (A >= 0 && A <=10 && B >=0 && B <=10 & C >=0 && C <=10){
        media = calcmedia(A,B,C);
        printf("A media foi %f.", media);
        if (media >= 6){
            printf("\nO aluno foi aprovado.");
        }
        else {
            printf("\nO aluno foi reprovado.");
        }
        if (media >= 4 & media <6){
            printf("\nO aluno esta apto a fazer a VS.");
        }
    }
    else{
        printf("As notas sao invalidas. Por favor, digite as notas variando de 0 a 10.");   
    }
    return 0;
}

float calcmedia(float num1, float num2, float num3) {

   float resultado;
 
   resultado = (num1+num2+num3)/3;
 
   return resultado;
}
