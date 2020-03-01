#include <stdio.h> /* printf */

#define max1(a, b) (a > b ? a : b)  //宏定义为直接替换，因此最好加上括号，即max2
#define max2(a, b) (((a) > (b)) ? (a) : (b))  //一般用法
// linux内核使用的用法，在max(a++,b++不会产生副作用，但是用了gnu的扩展，不属于ansi
// c的用法)
#define max3(a, b)                     \
    ({                                 \
        typeof(a) _max1 = (a);         \
        typeof(b) _max2 = (b);         \
        (void)(&_max1 == &_max2);      \
        _max1 > _max2 ? _max1 : _max2; \
    })

int main(int argc, char const *argv[]) {
    int a = 4, b = 2;
    printf("a=%d,b=%d\n", a, b);
    printf("max1(a,a+b)=%d\n", max1(a, a + b));
    printf("max2(a++,b++)=%d\n", max2(a++, b++));
    printf("a=%d,b=%d\n", a, b);
    printf("max3(a++,b++)=%d\n", max3(a++, b++));
    printf("a=%d,b=%d\n", a, b);
    return 0;
}
