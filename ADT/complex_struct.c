#include <math.h>  /* cos sin sqrt atan2 */
#include <stdio.h> /* printf */

typedef enum coordinate_type { RECTANGULAR, POLAR } ct;
// 设置t为直角坐标和极坐标，RECTANGULAR为直角坐标，POLAR为极坐标
typedef struct complex_struct {
    ct t;
    double x, y;
} cs;

//实部
double real(cs z) {
    switch (z.t) {
        case RECTANGULAR:
            return z.x;
        case POLAR:
            return z.x * cos(z.y);
    }
}

//虚部
double img(cs z) {
    switch (z.t) {
        case RECTANGULAR:
            return z.y;
        case POLAR:
            return z.x * sin(z.y);
    }
}

// 模
double mag(cs z) {
    switch (z.t) {
        case RECTANGULAR:
            return sqrt(z.x * z.x + z.y * z.y);
        case POLAR:
            return z.x;
    }
}

//辐角
double ang(cs z) {
    switch (z.t) {
        case RECTANGULAR:
            return atan2(z.x, z.y);
        case POLAR:
            return z.y;
    }
}

// 直角坐标转极坐标
void pol_to_rec(cs* z) {
    double x = real(*z);
    double y = img(*z);
    z->x = x;
    z->y = y;
    z->t = RECTANGULAR;
}

// 极坐标转直角坐标
void rec_to_pol(cs* z) {
    double x = mag(*z);
    double y = ang(*z);
    z->x = x;
    z->y = y;
    z->t = POLAR;
}

// 打印直角坐标
void print_complex(cs z) {
    if (z.t == POLAR) {
        pol_to_rec(&z);
    }
    if (fabs(z.y) < 1e-4) {
        printf("%.2f\n", z.x);
    } else if (fabs(z.x) < 1e-4) {
        printf("%.2fi\n", z.y);
    } else if (z.y < 0) {
        printf("%.2f-%.2fi\n", z.x, -z.y);
    } else {
        printf("%.2f+%.2fi\n", z.x, z.y);
    }
}

// 构造函数
cs make_from_real_img(double x, double y) {
    cs z;
    z.t = RECTANGULAR;
    z.x = x;
    z.y = y;
    return z;
}

cs make_from_mag_ang(double magnitude, double angle) {
    cs z;
    z.t = POLAR;
    z.x = magnitude;
    z.y = angle;
    return z;
}

// 四则运算
cs add_complex(cs z1, cs z2) {
    return make_from_real_img(real(z1) + real(z2), img(z1) + img(z2));
}

cs sub_complex(cs z1, cs z2) {
    return make_from_real_img(real(z1) - real(z2), img(z1) - img(z2));
}

cs mul_complex(cs z1, cs z2) {
    return make_from_mag_ang(mag(z1) * mag(z2), ang(z1) + ang(z2));
}

cs div_complex(cs z1, cs z2) {
    return make_from_mag_ang(mag(z1) / mag(z2), ang(z1) - ang(z2));
}

int main(int argc, char const* argv[]) {
    cs z1 = make_from_real_img(3.0, 4.0);
    cs z2 = make_from_mag_ang(5.0, 0.925);
    print_complex(z1);
    print_complex(z2);

    cs z;
    z = mul_complex(z1, z2);
    print_complex(z);
    return 0;
}
