

# include "draw.h"

// Implement your draw functions here

Vec eval_bezier (float t, std::vector<Vec>& pnts)
{
	Vec B;
	return B;

}
Vec eval_lagrange (float t, std::vector<Vec>& pnts)
{
	Vec B;
	float p = 1;
	int n = pnts.size() - 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j != i)p *= ( t - (float(j)/float(n)) ) / ( (float(i)/float(n)) - (float(j)/float(n)) );
		}

		B.x += p * pnts[i].x;
		B.y += p * pnts[i].y;
		p = 1;
	}

	return B;
}

Vec eval_bspline ( float t, int k, std::vector<Vec>& pnts )
{
	Vec B;
	k = float(k);
	float u = ( (k - 1) * (1 - t) + (t * (float(pnts.size() - 1) + 1 ) ) );
	float knotVal;

	for (int i = 0; i < pnts.size(); i++ )
	{
		knotVal = N(i, k, u);
		B.x += knotVal * pnts[i].x;
		B.y += knotVal * pnts[i].y;
	}

	return B;
}
float N ( int i, int k, float u )
{
	float ui=float(i);
	if ( k==1 )
		return ui<=u && u<ui+1? 1.0f:0;
	else
		return ((u-ui)/(k-1)) * N(i,k-1,u) + ((ui+k-u)/(k-1)) * N(i+1,k-1,u);
}
