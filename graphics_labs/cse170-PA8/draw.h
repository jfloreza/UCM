# pragma once
# include "vec.h"
# include <vector>


// Declare of your draw functions here

Vec eval_bezier (float t, std::vector<Vec>& pnts);
Vec eval_lagrange (float t, std::vector<Vec>& pnts);
Vec eval_bspline ( float t, int k, std::vector<Vec>& pnts );
float N (int i, int k, float u);
