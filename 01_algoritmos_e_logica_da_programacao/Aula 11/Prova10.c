#include <stdio.h>

int main ()
{
    float media=0, n1=0, x=0;
    while (n1>=0){
        printf ("Insira um valor positivo (insira um negativo para finalizar): ");
        scanf ("%f", &n1);
        media = media +n1;
        x++;
    }
    media = media/x;
    printf ("A media e: %.2f", media);
    
    return 0;
}