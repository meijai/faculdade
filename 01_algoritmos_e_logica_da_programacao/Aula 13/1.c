//Alunos: Bruno Furlan e Lucas Piva Bellaver

#include<stdio.h>
int main()
{
    float A[7][4];
    int i, j;
    int ii, jj;
    int iii, jjj;
    float md=0; //media diaria de temperatura
    float m0=0, m1=0, m2=0, m3=0;
    float d0=0, d1=0, d2=0, d3=0, d4=0, d5=0, d6=0;
    float maior=0, menor=100;
    for(i=0; i<7; i++){
        for(j=0; j<4; j++){
            printf("Informe a temperatura do dia %d, horario %d: ",i,j);
            scanf("%f", &A[i][j]);
            if(A[i][j] >= maior){
                maior=A[i][j];
                ii=i;
                jj=j;
            }
            else if(A[i][j] <= menor){
                menor=A[i][j];
                iii=i;
                jjj=j;
            }
        }
    }
    for(i=0; i<7; i++){
        for(j=0; j<4; j++){
            md=md+A[i][j];
        }
    }
    for(i=0; i<7; i++){
        for(j=0; j<4; j++){
            if(j==0){
                m0=m0+A[i][j];
            }
            else if(j==1){
                m1=m1+A[i][j];
            }
            else if(j==2){
                m2=m2+A[i][j];
            }
            else if(j==3){
                m3=m3+A[i][j];
            }
        }
    }
    for(i=0; i<7; i++){
        for(j=0; j<4; j++){
            if(i==0){
                d0=d0+A[i][j];
            }
            else if(i==1){
                d1=d1+A[i][j];
            }
            else if(i==2){
                d2=d2+A[i][j];
            }
            else if(i==3){
                d3=d3+A[i][j];
            }
            else if(i==4){
                d4=d4+A[i][j];
            }
            else if(i==5){
                d5=d5+A[i][j];
            }
            else if(i==6){
                d6=d6+A[i][j];
            }
        }
    }
    d0=d0/4;
    d1=d1/4;
    d2=d2/4;
    d3=d3/4;
    d4=d4/4;
    d5=d5/4;
    d6=d6/4;
    m0=m0/7;
    m1=m1/7;
    m2=m2/7;
    m3=m3/7;
    md=md/28;
    
    printf("\n\t\tMEDIAS POR DIA\n\n");
    printf("A media de temperatura do domingo e de %.2f graus celsius.\n", d0); // media temperatura 0
    printf("A media de temperatura da segunda e de %.2f graus celsius.\n", d1); // media temperatura 1
    printf("A media de temperatura da terca e de %.2f graus celsius.\n", d2); // media temperatura 2
    printf("A media de temperatura da quarta e de %.2f graus celsius.\n", d3); // media temperatura 3
    printf("A media de temperatura da quinta e de %.2f graus celsius.\n", d4); // media temperatura 4
    printf("A media de temperatura da sexta e de %.2f graus celsius.\n", d5); // media temperatura 5
    printf("A media de temperatura do sabado e de %.2f graus celsius.\n\n\n", d6); // media temperatura 6
    printf("\n\t\tMEDIAS POR HORARIO\n\n");
    printf("A media diaria total de temperatura e de %.2f graus celsius.\n", md); //media diaria total de temperatura
    printf("A media de temperatura no horario 1 e de %.2f graus celsius.\n", m0); //media temperatura horario 1(0)
    printf("A media de temperatura no horario 2 e de %.2f graus celsius.\n", m1); //media temperatura horario 2(1)
    printf("A media de temperatura no horario 3 e de %.2f graus celsius.\n", m2); //media temperatura horario 3(2)
    printf("A media de temperatura no horario 4 e de %.2f graus celsius.\n\n\n", m3); //media temperatura horario 4(3)
    printf("\n\t\tTEMPERATURAS EXTREMAS\n\n");
    printf("Maior temperatura e de %.2f graus celsius no dia %d, horario %d.\n", maior, ii, jj);
    printf("Menor temperatura e de %.2f graus celsius no dia %d, horario %d.\n", menor, iii, jjj);
}