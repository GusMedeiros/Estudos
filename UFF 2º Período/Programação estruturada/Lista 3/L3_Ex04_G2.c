#include <stdio.h>

int divs(int n, int*max, int *min){
    int i, qnt=0;

    for (i=2; i<=n/2; i++) {
        if (n%i == 0) {
            qnt++;
            break;
        }
    }

    if (qnt == 0)
        return 0;
    else{
        *min=i;
        *max=n/(*min);
        return 1;
    }
}

int main() {
    int n, max, min;
    printf("Digite o numero: ");
    scanf("%d", &n);
    printf("%d \n", divs(n, &max, &min));
    printf("Max: %d \n", max);
    printf("Min: %d \n", min);
    return 0;
}
