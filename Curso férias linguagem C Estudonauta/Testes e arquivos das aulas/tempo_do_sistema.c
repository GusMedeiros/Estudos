# include <time.h>

void main() {
    time_t t;
    time(&t);
    struct tm *data;
    data = localtime(&t);
    int d = data -> tm_mday;

}