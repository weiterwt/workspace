#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	return 0;
}

int getline(char *s, int lim)
{
	int c;
	char *t = s;

	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - t;
}

int atoi(char *s)
{
	int n, sign;
	for (; isspace(*s); s++)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	for (n = 0; isdigit(*s); s++)
		n = 10 * n + *s - '0';
	return sign * n;
}

void reverse(char *s)
{
	int c;
	char *t;

	for (t = s + (strlen(s) - 1); s < t; s++, t--)
	{
		c = *s;
		*s = *t;
		*t = c;
	}
}

void itoa(int n, char *s)
{
	int sign;
	char *t = s;

	if ((sign = n) < 0)
		n = -n;
	do
	{
		*s++ = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(t);
}

double atof(char *s)
{
	double val, power;
	int sign;

	for (; isspace(*s); s++)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	for (val = 0.0; isdigit(*s); s++)
		val = 10.0 * val + (*s - '0');
	if (*s == '.')
		s++;
	for (power = 1.0; isdigit(*s); s++)
	{
		val = 10.0 * val + (*s - '0');
		power *= 10.0;
	}
	return sign * val / power;
}