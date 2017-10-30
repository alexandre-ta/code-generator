/* sample 5 */
struct str
{
	int a;
};

int useless(int c)
{
	int res = 0;
	res+= c;
	if(c < 10)
		return res;
	else
		return 0;
}

int main()
{
	read(str.a);
	useless(str.a);
	return 0;
}