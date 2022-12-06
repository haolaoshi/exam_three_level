int shared = 1;
/*程序员的自我修养*/
void swap(int* a, int* b)
{
    *a ^= *b ^= *a ^= *b;
}
