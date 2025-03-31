/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int isValid(char *num) {
    int len = strlen(num);
    if (len == 1) return 1; // Single digit is always valid
    if (num[0] == '0' && num[len - 1] == '0') return 0; // Leading and trailing zeros are not allowed
    if (num[0] == '0' && num[1] != '\0') return 0; // Leading zero in a multi-digit number is not allowed
    return 1;
}

// Generate all possible valid representations of a number by inserting a decimal point
char** generateValidNumbers(char *num, int *size) {
    int len = strlen(num);
    char **res = (char **)malloc(sizeof(char *) * (len));
    *size = 0;
    
    if (isValid(num)) {
        res[*size] = strdup(num);
        (*size)++;
    }
    
    for (int i = 1; i < len; i++) {
        char left[i + 1];
        char right[len - i + 1];
        strncpy(left, num, i);
        left[i] = '\0';
        strcpy(right, num + i);
        
        if (isValid(left) && right[len - i - 1] != '0') {
            char *temp = (char *)malloc(len + 2);
            sprintf(temp, "%s.%s", left, right);
            res[*size] = temp;
            (*size)++;
        }
    }
    return res;
}

// Comparator function for sorting
int cmp(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Main function to generate ambiguous coordinates
char** ambiguousCoordinates(char* s, int* returnSize) {
    int len = strlen(s);
    char **result = (char **)malloc(sizeof(char *) * 1000);
    *returnSize = 0;
    
    for (int i = 1; i < len - 2; i++) {
        char left[i+1];
        char right[len - i - 2+1];
        strncpy(left, s + 1, i);
        left[i] = '\0';
        strncpy(right, s + i + 1, len - i - 2);
        right[len - i - 2] = '\0';
        
        int leftSize = 0, rightSize = 0;
        char **leftNums = generateValidNumbers(left, &leftSize);
        char **rightNums = generateValidNumbers(right, &rightSize);
        
        for (int j = 0; j < leftSize; j++) {
            for (int k = 0; k < rightSize; k++) {
                char *formatted = (char *)malloc(strlen(leftNums[j]) + strlen(rightNums[k]) + 5);
                sprintf(formatted, "(%s, %s)", leftNums[j], rightNums[k]);
                result[*returnSize] = formatted;
                (*returnSize)++;
            }
        }
        
        for (int j = 0; j < leftSize; j++) free(leftNums[j]);
        for (int k = 0; k < rightSize; k++) free(rightNums[k]);
        free(leftNums);
        free(rightNums);
    }
    
    qsort(result, *returnSize, sizeof(char *), cmp);
    return result;
}