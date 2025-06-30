#include <stdio.h>

#define PI 3.14
#define area(radius) (PI * radius * radius)

int main() {
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    //area = PI * radius * radius;
    printf("The area of the circle is %.2f\n", area(radius));

    return 0;
}
