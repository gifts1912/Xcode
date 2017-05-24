#include <iostream>
#include <cstring>

using namespace std;


void getmem_const(const char * const p){
    return;
}

int getMem_twoParagraphLen(char **p1, int *len1, char **p2, int *len2) {
    char *tmp1 = NULL;
    tmp1 = (char*) malloc(100);
    if(tmp1 == NULL){
        return -1;
    }
    strcpy(tmp1, "abcd");
    *p1 = tmp1;
    *len1 = strlen(tmp1);
    
    char *tmp2 = NULL;
    tmp2 = (char*) malloc(100);
    if(tmp2 == NULL) {
        return -1;
    }
    strcpy(tmp2, "1234");
    *len2 = strlen(tmp2);
    *p2 = tmp2;

    return 0;
}

int freeMem(char **p){
    if (*p == NULL) {
        return -1;
    }
    free(*p);
    *p = NULL;
    return 0;
}

int constPointer(){
    const char * p1 = NULL ;
    const int a = 10;
    {
        int *p =(int *) (&a); //have copy process in background.
        *p = 100;
        printf("a:%d\n", a);
        printf("*p:%d\n", *p);
    }
    cout << "Hello world!" << endl; 
    return 0;
}

int main() {
    char *p1 = NULL;
    int len1;
    char *p2 = NULL;
    int len2;

    getMem_twoParagraphLen(&p1, &len1, &p2, &len2);
    printf("p1:%s:\tlen1:%d:\n", p1, len1);
    printf("p2:%s:\tlen2:%d:\n", p2, len2);

    freeMem(&p1);
    freeMem(&p2);

    return 0;
}
