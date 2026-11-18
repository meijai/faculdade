#include<stdio.h>
int main()
{
    char str1[100], str2[100];
    printf("Informe uma palavra: ");
    scanf("%s", str1);
    printf("Informe outra palavra: ");
    scanf("%s", str2);
    printf("A primeira palavra e: '%s' e a segunda letra dela e: '%c'.\n", str1, str1[1]);
    printf("A segunda palavra e: '%s' e a segunda letra dela e: '%c''.\n", str2, str2[1]);
}