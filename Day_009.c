/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation
*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;
    char temp;

    printf("Enter the code name: ");
    scanf("%s", str);   // no spaces as per problem

    len = strlen(str);

    // Reverse the string
    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    printf("Mirrored code name: %s\n", str);

    return 0;
}
