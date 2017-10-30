/* Compute Fibonacci */
int mat[4]={0,1,1,1};
int n;
int t=98;

int solve(int x)
{
	int p,q,r,s;
	int ans[2]={0,1};
	for(;x;x>>=1)
	{
		if(x&1)
		{
			p=ans[0]*mat[0]+ans[1]*mat[2];
			q=ans[0]*mat[1]+ans[1]*mat[3];
			ans[0]=p%t;;
			ans[1]=q%t;
		}
		p=mat[0]*mat[0]+mat[1]*mat[2];
		q=mat[0]*mat[1]+mat[1]*mat[3];
		r=mat[2]*mat[0]+mat[3]*mat[2];
		s=mat[1]*mat[2]+mat[3]*mat[3];
		mat[0]=p%t;
		mat[1]=q%t;
		mat[2]=r%t;
		mat[3]=s%t;
		write(mat[0]);
		write(mat[1]);
		write(mat[2]);
		write(mat[3]);
	}
	return ans[0];
}

int main()
{
	read(n);
	write(solve(n));
	return 0;
}
