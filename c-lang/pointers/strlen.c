/* returns the length of a string */
int strlen(char *p)
{
    int n = 0;
    for (; *p != '\0'; p++)
        n++;
    return n;
}