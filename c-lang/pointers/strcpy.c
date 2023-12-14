

/* strcpy:  copy t to s; array subscript version */
void strcpy(char *s, char *t)
{
    iht i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

/* strcpy:  copy t to s; pointer version 1 */
void v1strcpy(char *s, char *t)
{
   while ((*s = *t) != '\0') {
       s++;
       t++;
   }
}

/* strcpy:  copy t to s; pointer version 2 */
void v2strcpy(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}

/* strcpy:  copy t to s; pointer version 3 */
void v3strcpy(char *s, char *t)
{
    while ((*s++ = *t++))
        ;
}