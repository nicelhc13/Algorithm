#include <stdio.h>
#include <math.h>

int tc, m, s, c;

double getHeight(double a, double b, double c)
{
	// a == r1, b == r2, c == d;
	// using heron equation!
	double s = (a+b+c)/2;
	return sqrt((double)s*(s-a)*(s-b)*(s-c))*2/c;
}

double calcRestArea()
{
	double h = getHeight(m, s, c);
	return (m*m*acos(-1.0)+h*c-(m*m*asin(h/m)+s*s*asin(h/s)));
}

int main(void)
{
	int i;
	scanf("%d",  &tc);
	for(i = 0; i < tc; i++) {
		scanf("%d %d %d", &m, &s, &c);
		printf("%.3lf\n", calcRestArea());
	}
	return 0;
}

