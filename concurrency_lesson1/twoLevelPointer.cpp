#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int Sort01(char ** arr, int num) {
    char *tmp = NULL;
    for (int i = 0; i < num - 1; i++) {
        for(int j = i + 1; j < num; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                tmp = arr[i]; // swaper pointer
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    return 0;
}

void PrintArray(char ** arr, int num) { // It's different with Printf02; as one step on arr have different distance with pointer add 1 in Printf02;
    for(int i = 0; i < num; i++) {
        printf("%s\n", arr[i]);
    }
}

int main1(){
    char * arr[] = {(char*) "abcd", (char *) "1234", (char *) "bbbbb"};
    int num = sizeof(arr) / sizeof(arr[0]);

    PrintArray(arr, num);
    Sort01(arr, num);
    printf("\nSort\n");
    PrintArray(arr, num);

    return 0;
}

void Printf02(char (* arr)[40], int n) { // arr ++ will have 40 char step distance
    for(int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}
int Sort02(char myArray[10][40], int num) {
    char buf[40];
    for(int i = 0; i < num-1; i++) {
        for(int j = i+1; j < num; j++) {
            if(strcmp(myArray[i], myArray[j]) > 0) {
                strcpy(buf, myArray[i]); // change memory block
                strcpy(myArray[i], myArray[j]);
                strcpy(myArray[j], buf);
            }
        }
    }
    return 0;
}

int main02(){
    int i = 0, num = 4;
    char myArray[10][40] = {"aaaa", "bbbb", "cccc", "1111"};
    printf("dim1:%lu\n", sizeof(myArray)/sizeof(myArray[0]));
    Printf02(myArray, num);
    printf("After sorted!\n");
    Sort02(myArray, num);
    Printf02(myArray, num);
    return 0;
}

int Sort03(char ** arr, int num) {
    char buf[100];
    if (arr == NULL) {
        return -1;
    }
    for(int i = 0;i < num - 1; i++) {
        for(int j = i+1; j < num; j++) {
            if(strcmp(arr[i], arr[j]) < 0){
               /* 
                char *tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                */
                strcpy(buf, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], buf);
            }
        }
    }
    return 0;
}

void Print03(char ** arr, int num) {
    for (int i = 0; i < num; i++) {
        printf("%s\n", arr[i]);
    }
}

int Free03(char ***ptr, int num) {
    if (ptr == NULL) {
        return -1;
    }
    for(int i = 0;i < num; i++) {
        if((*ptr)[i] == NULL){
            continue;
        }
        free((*ptr)[i]);
        (*ptr)[i] = NULL;
    }
    free(*ptr);
    *ptr = NULL;
    return 0;
}

int main() {
    int num = 5;
    char **ptr = (char **) malloc(sizeof(char *) * num);
    for(int i = 0; i < num; i++) {
        ptr[i] = (char *) malloc(100 * sizeof(char));
        sprintf(ptr[i], "%d\t%d\t%d", i+1, i+1, i+1);
    }

    printf("Before Sort\n");
    Print03(ptr, num);
    Sort03(ptr, num);
    printf("After Sort\n");
    Print03(ptr, num);
    Free03(&ptr, num);
    
    
    return 0;
}
