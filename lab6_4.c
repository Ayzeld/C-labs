#include <stdio.h>

int main() {
int a[5]={12, 53, 83, 1, -20};
int b[5]={48, 6, -85, 76, 11};
int as = sizeof(a)/sizeof(a[0]);
int c[as];
for (int i=0; i < as; i++) {
    c[i] = a[i] + b[i];
}
int r=0;
for (int i=0; i < as; i++) {
    if (i%2 == 0 & a[i] > r) {
        r=a[i];
    }
}
printf("%d \n", r);
int m=0;
for (int i=0; i < as; i++) {
    if (i%2 == 1 & b[i] < 0) {
        m=m+1;
    }
}
printf("%d \n", m);
int s=0;
for (int i=0; i < as; i++) {
    s=s+c[i];
}
printf("%d \n", s/as);
}

