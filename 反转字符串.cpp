void reverseString(char* s, int sSize)
{
    char * head = s;
    char * tail = s + sSize -1;
    while(tail - head > 0)
    {
        char tmp = 0;
        tmp = *head;
        *head = *tail;
        *tail = tmp;
        head++;
        tail--;
    }
}
