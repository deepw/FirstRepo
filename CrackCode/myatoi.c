/* Implement atoi to convert a string to an integer. */



int myAtoi(char* str) {
    char *c; double tmp=0; int negative = 0;
    c=str;
    if (!str) {
        return -1;
    }
    if (*c == '-') {
        negative = 1;
        c++;
    }
    while (*c != '\0') {
        if (*c < '0' || *c > '9') {
            return -1;
        }
        tmp = (tmp*10) + (*c-48);
        if (tmp > INT_MAX || (negative && tmp > INT_MAX/2)) {
            return -1;
        }
        c++;
    }
    if (negative) {
        return (int) (-tmp);
    }
    return (int) tmp;
}
