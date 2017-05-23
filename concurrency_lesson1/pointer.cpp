#include <iostream>
#include <cstring>

using namespace std;

int copy_str(char * from, char * to){
    if (from == NULL || to == NULL) {
        return -1;
    }
    int len = strlen(from);
    strncpy(to, from, len);
    to[len] = '\0';
    return 0;
}

char * strcat_my(char *x, char *y) {
    char *p = (char *) malloc(strlen(x) + strlen(y) + 1);
    char *ptr = p;
    while((*(ptr++) = *(x++)) != '\0') {
    }
    ptr--;
    while((*(ptr++) = *(y++)) != '\0');

    return p;
}

int subStrOccurence(char *p, char *sub, int * num) {
    if(p == NULL || sub == NULL || num == NULL) {
        return -1;
    }   
    char *pre = p;
    int pos = 0, n = 0;
    while((pre = strstr(pre, sub)) != NULL) {
        n++;
        pre = pre + strlen(sub);
    }
    *num = n;
    return 0;
}

int main(){
    char p[1024] = "abcde";
    char *to = (char*) malloc(sizeof(p));
    copy_str(p, to);
    printf("to:%s:\n", to);
    free(to);
    char *x = (char*)"abcd";
    char *y = (char*) "1234";
    char *z = strcat_my(x, y);
    printf("z:%s:\n", z);
    free(z);


    printf("subStrOccurence test\n");
    char ptr[] = "ab\tqabqwab";
    int n = 0;
    subStrOccurence(ptr, (char*)"ab", &n);
    printf("n:%d\n", n);
    return 0;
}
