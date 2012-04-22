
# include <math.h>
# include "vec.h"

const float srpi = 3.14159265f;
const float srtiny = 1.0E-6f;
# define SRNEXTZ(a,eps) ( (a)>-(eps) && (a)<(eps) )

float Vec::len () const
 {
   float f = x*x + y*y + z*z;
   if ( f>0 ) f = sqrtf ( f );
   return f;
 }

float Vec::len ( float n )
 {
   float f = sqrtf (x*x + y*y + z*z);
   if ( f>0 ) { n/=f; x*=n; y*=n; z*=n; }
   return f;
 }

Vec cross ( const Vec& v1, const Vec& v2 )
 {
   return Vec ( v1.y*v2.z - v1.z*v2.y,
                v1.z*v2.x - v1.x*v2.z,
                v1.x*v2.y - v1.y*v2.x  );
 }

float dist ( const Vec& v1, const Vec& v2 )
 {
   Vec v ( v2-v1 );
   return v.len();
 }
