bool isSubsequence(char* s, char* t) {
    
    while (*t)
        {  //printf("%c ",s);
            s += *s == *t++;
            //printf("%c ",s);
        }
    return !*s;
}