/* omnidirectional plane-wave destruction */

#include <rsf.h>

static float radius;
static int n1, n2;

void fbpwd_init(int nn1, int nn2, float rad) 
/*< initialize >*/
{
	radius = rad;
	n1 = nn1;
	n2 = nn2;
}



#define POW(a, b) (b<0?0.0:(b==0?1.0:pow(a,b)))

void fbpwd(int m1, int m2, float ****in, float **dip)
/*< omnidirectional dip estimation >*/
{
	int i1, j1, j2;
	double  s1, c1;

	for(i1=0; i1<n1*n2; i1++)
	{
		s1 = radius*cimagf(dip[0][i1]);
		c1 = radius*crealf(dip[0][i1]);
		dip[0][i1] = 0.0;
		for(j2=0; j2<m2; j2++)
		for(j1=0; j1<m1; j1++)
		{
			if((j1+j2)%2==0) continue;
			dip[0][i1] += 2.0*in[j2][j1][0][i1]*POW(s1, j1)*POW(c1,j2);
		}
	}

}



