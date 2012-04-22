#ifdef WIN32
    #include <sys/types.h>
    #include <sys/timeb.h>
    #else
    #include <sys/time.h>
    #endif


    double get_time ()
    {
      #ifdef WIN32
       // if better precision is needed in Windows, use QueryPerformanceCounter
       _timeb tp;
       _ftime_s(&tp);
       return 0.001*(double)tp.millitm + (double)tp.time;
      #else
       timeval tp;
       if ( gettimeofday(&tp,0)==-1 ) return 0;
       return 0.000001*(double)tp.tv_usec + (double)tp.tv_sec;
      #endif
   } 