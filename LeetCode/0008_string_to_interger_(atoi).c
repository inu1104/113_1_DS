int isDigit(char c)
{
    if (c - '0' < 10 && c - '0' >= 0)
        return 1;
    return 0;
}

int myAtoi(char* s) {
    long long int result = 0, idx = 0, isPlus = 1;
    
    while (s[idx] == ' ')
    {
        idx++;
    }

    if(s[idx] == '-'){
        isPlus = -1;
        idx++;
    }else if(s[idx] == '+') idx++;

    for(; s[idx] != '\0'; idx++){
        if(!isDigit(s[idx])) break;
        else{
            result *= 10;
            result += (s[idx] - '0');
            if(result >= (long long)INT_MAX && isPlus == 1) return INT_MAX;
            else if (result >= (long long)INT_MAX + 1 && isPlus == -1) return INT_MIN;
        }
    }


    result *= isPlus;
    printf("%d %ld", isPlus, result);
    
    return (int)result;
}
