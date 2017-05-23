#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char  g_buf[100];

int getCount(char * ptr, char * pos, int *num){
    char *v = ptr;
    if (v == NULL || pos == NULL){
        return -1;
    }
    int i = 0, j = strlen(v) - 1;
    while(v[i] != '\0' && isspace(v[i])){
        i++;
    }
    while(j >= 0 && isspace(v[j])){
        j--;
    }
    * num = j - i + 1;
    strncpy(pos, ptr + i, *num);
    pos[*num] = '\0';
    return 0;
}

int trim(char *v){
    if (v == NULL){
        return -1;
    }
    int i = 0, j = strlen(v) - 1;
    while(v[i] != '\0' && isspace(v[i])) {
        i++;
    }
    while(j >= 0 && isspace(v[j])) {
        j--;
    }
    memmove(v, v + i, j - i + 1); // error if v point to global memeory chunk, because the variable in gloabl can't be writed.
    v[j -i + 1] = '\0';
    return 0;
}

int trimCall(){
    char* v = (char*) "  aabbcd  ";
    char *res = NULL;
    res = (char *) malloc(100);
    int num = 0;
    //getCount(v, res, &num);
    char buf[] = " aabbcc  ";
    printf("beforeBuf:%s:end\n", buf);
    trim(buf); // trim(v) will cause busy error 10; as varaiable in global memory chunk cann't be write.
    printf("afterBuf:%s:end\n", buf);
    return 0;
}

int Inverse(char *v){
    if (v == NULL){
        return -1;
    }
    int i = 0, j = strlen(v) - 1;
    while( i < j ){
        char c = v[i];
        v[i] = v[j];
        v[j] = c;
        i++;
        j--;
    }
    return 0;
}
int Inverse02(char *v){
    if (v == NULL){
        return -1;
    }
    char *b = NULL, *e = NULL;
    int len = strlen(v);
    b = v;
    e = v + len - 1;
    while( b < e){
        char c = *b;
        *b = *e;
        *e = c;
        b++;
        e--;
    }
    return 0;
}

int Inverse03(char *v){
    if (v == NULL) {
        return -1;
    }
    if (*(v + 1) != '\0'){
        Inverse03(v+1);
    }
    printf("%c", *v);
    return 0;
}

int Inverse04(char *v){
    if (v == NULL) {
        return -1;
    }
    if (*(v + 1) != '\0'){
        Inverse04(v+1);
    }
    strncat(g_buf, v, 1); // strcat(g_buf, v); will copy all v pointer char * to g_buf;
    return 0;
}

int Inverse05(char *v, char *buf){
    if (v == NULL || buf == NULL) {
        return -1;
    }
    if (*v == '\0') {
        return 0;
    }
    Inverse05(v + 1, buf);
    strncat(buf, v, 1);
    return 0;
}

int main(){
    char t[10];
    memset(t, '-', sizeof(t));
    t[sizeof(t) - 1] = '\0';
    printf("t1:%s\n",t);
    memset(t, 0, sizeof(t));
    printf("t2:%s:\n", t);
    memset(t, '\0', sizeof(t));
    printf("t3:%s:\n",t);
    memset(g_buf, '\0', sizeof(g_buf));
    char v[] = "abcde";
    char buf[1024];
    memset(buf, '\0', sizeof(buf));
    printf("v:%s\n", v);
    Inverse05(v, buf);
    printf("inversev:%s\n", buf);
    return 0;
}
