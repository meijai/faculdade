#include<stdio.h>
int main()
{
    float ne, nf=0, rs, ms, mf, mp, s1, s2, s3;
    while(ne<200){
        printf("Informe seu salario: ");
        scanf("%f", &s1);
        if(s1<=1500){
            s2=s2+s1;
            mp++;
        }
        if(s1>s3){
            s3=s1;
        }
        ms=ms+s1;
        printf("informe a quantidade de filhos: ");
        scanf("%f", &nf);
        mf=mf+nf;
        ne++;
    }
    ms=ms/ne;
    mf=mf/ne;
    mp=(mp/ne)*100;
    printf("Media salarial de: %.2f R$.\n", ms);
    printf("Media de filhos: %.2f filhos.\n", mf);
    printf("O maior salario: %.2f R$.\n", s3);
    printf("Porcentagem de pobres: %.2f.\n", mp);
}