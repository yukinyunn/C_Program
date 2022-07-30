#include <stdio.h>
#include <string.h>

int main (void) {
    char str[100];
    int len;

    printf("文字列str用の文字列を英語で入力してください\n -->");
    fgets(str, 100, stdin);  //標準出力より1行分の入力

    len = strlen(str);  //strの文字列の長さを測る
    printf("文字配列strの内容は\"%s\"で文字数は改行も含めて%d です\n", str, len);
    str[len-1] = '\0';  //改行コードをNULL文字に置き換える
    printf("文字配列strの内容は\"%s\"で文字数は%d です\n", str, len-1);

    return 0;
}