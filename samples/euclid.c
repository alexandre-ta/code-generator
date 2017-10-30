/* Euclid file */
int read(int a)
{}

int write(int g)
{}

int gcd(int x,int y)
{
	if(!y)
		return x;
	return gcd(y,x%y);
}

int main()
{
	int a,b;
	read(a);
	read(b);
	write(gcd(a,b));
	return 0;
}
