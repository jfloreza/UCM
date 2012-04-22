// Ensure the header file is included only once in multi-file projects
// Pragma once is a non-standard but widely supported preprocessor directive
# pragma once

// A vector
class Vec
 { public :
    float x, y, z;

   public :

    /*! constructor from x y z values */
    Vec ( float a=0, float b=0, float c=0 ) { x=a; y=b; z=c; }

    /*! set x y z values */
    void set ( float a, float b, float c ) { x=a; y=b; z=c; }

    /*! get the length (norm) of the vector */
    float len () const;

    /*! change the length of the vector to n and returns the old length */
    float len ( float n );

    /*! normalization */
    void normalize () { float l=len(); if(l>0) {x/=l; y/=l; z/=l;} }

    /*! cross product */
    friend Vec cross ( const Vec& v1, const Vec& v2 );

    /*! distance */
    friend float dist ( const Vec& v1, const Vec& v2 );

    /*! dot product */
    friend float dot ( const Vec& v1, const Vec& v2 )
           { return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z; }

    /*! vector addition */
    friend Vec operator + ( const Vec& v1, const Vec& v2 ) 
           { return Vec (v1.x+v2.x, v1.y+v2.y, v1.z+v2.z); }

    /*! vector subtraction */
    friend Vec operator - ( const Vec& v1, const Vec& v2 ) 
           { return Vec (v1.x-v2.x, v1.y-v2.y, v1.z-v2.z); }

    /*! multiplication by scalar */
    friend Vec operator * ( const Vec& v, float r )
           { return Vec (v.x*r, v.y*r, v.z*r); }

    /*! division by scalar */
    friend Vec operator / ( const Vec& v, float r )
           { return Vec (v.x/r, v.y/r, v.z/r); }
 };

