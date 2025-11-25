#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *data;
    int length;
} requiredResultFormat;

requiredResultFormat getLength(long long n){
    requiredResultFormat result;
    char buffer[22];
    snprintf(buffer,sizeof(buffer),"%lld",n);
    int length = strlen(buffer);
    result.data = malloc((length + 1) * sizeof(char));
    strcpy(result.data, buffer);
    result.length = length;
    return result;
}

int main(){
    long long cardNumber = get_long("Input your credit card number => ");
    // long long cardNumber = 369421438430814;
    string cardIssuer = "INVALID\n";
    requiredResultFormat result = getLength(cardNumber);
    int everyOtherNumberTotal = 0;
    int count=1;
    int drest = 0;
    while(true){
        int stat = cardNumber % 10;
        if(count % 2 == 0){
            int cur = stat * 2;
            for(;cur > 0; cur /=10){
                int d = cur%10;
                everyOtherNumberTotal += d;
            }
        }else{
            drest += stat;
        }
        if(count == result.length){
            break;
        }
        cardNumber /= 10;
        count++;
    }
    everyOtherNumberTotal += drest;
    if(everyOtherNumberTotal % 10 == 0){
        if(result.length == 15 && result.data[0] == '3' && (result.data[1] == '4' || result.data[1] == '7')){
            cardIssuer = "AMEX\n";
        }else if(result.length == 13){
            cardIssuer = "VISA\n";
        }else if(result.length == 16){
            if(result.data[0] == '4'){
                cardIssuer = "VISA\n";
            }else if(result.data[0] == '5' && (result.data[1] >='1' && result.data[1] <= '5')){
                cardIssuer = "MASTERCARD\n";
            }
        }
    }
        printf("%s",cardIssuer);
        free(result.data);
        return 0;
}
