#include <stdio.h>
#include <string.h>
int main() {
char str1[100], str2[100];
int result;
printf("Digite alguma coisa: ");
fgets(str1, sizeof(str1), stdin);
printf("Digite outra coisa: ");
fgets(str2, sizeof(str2), stdin);
result = strcmp(str1, str2);
if(result == 0) {
printf("Strings iguais\n");
}
else {
printf("Strings diferentes\n");
}
return 0;
}