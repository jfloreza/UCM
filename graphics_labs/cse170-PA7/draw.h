# pragma once
# include <stdlib.h>
# include <vector>
# include "vec.h"

// Declare of your draw functions here
Vec eval_bezier (float t, std::vector<Vec>& pnts);
Vec eval_lagrange (float t, std::vector<Vec>& pnts);


