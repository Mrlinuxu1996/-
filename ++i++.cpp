#include <cstdio>
using namespace std;

int main()

{

    int i = 1;
    int a;
    a=i++;
    printf("a=%d i=%d\n", a, i);

    printf("%d %d\n", ++i, ++i);

    printf("%d %d\n", ++i, i++);

    printf("%d %d\n", i++, i++);

    printf("%d %d\n", i++, ++i);

    return 0;

}