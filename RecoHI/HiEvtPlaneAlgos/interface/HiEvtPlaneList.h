#ifndef __HiEvtPlaneList__
#define __HiEvtPlaneList__
/*
Index     Name   Detector Order hmin1 hmax1 hmin2 hmax2 minpt maxpt nsub mcw    rmate1    rmate2
    0      HFm2        HF     2 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp2 trackmid2
    1      HFp2        HF     2  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm2 trackmid2
    2 trackmid2   Tracker     2 -0.75  0.75  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
    3     HFm2a        HF     2 -5.00 -4.00  0.00  0.00  0.01 30.00 3sub  no      HFp2 trackmid2
    4     HFp2a        HF     2  4.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm2 trackmid2
    5     HFm2b        HF     2 -4.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp2 trackmid2
    6     HFp2b        HF     2  3.00  4.00  0.00  0.00  0.01 30.00 3sub  no      HFm2 trackmid2
    7     HFm2c        HF     2 -3.00 -2.00  0.00  0.00  0.01 30.00 3sub  no      HFp2 trackmid2
    8     HFp2c        HF     2  2.00  3.00  0.00  0.00  0.01 30.00 3sub  no      HFm2 trackmid2
    9      HFm3        HF     3 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp3 trackmid3
   10      HFp3        HF     3  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3 trackmid3
   11 trackmid3   Tracker     3 -0.75  0.75  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   12     HFm3a        HF     3 -5.00 -4.00  0.00  0.00  0.01 30.00 3sub  no      HFp3 trackmid3
   13     HFp3a        HF     3  4.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3 trackmid3
   14     HFm3b        HF     3 -4.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp3 trackmid3
   15     HFp3b        HF     3  3.00  4.00  0.00  0.00  0.01 30.00 3sub  no      HFm3 trackmid3
   16     HFm3c        HF     3 -3.00 -2.00  0.00  0.00  0.01 30.00 3sub  no      HFp3 trackmid3
   17     HFp3c        HF     3  2.00  3.00  0.00  0.00  0.01 30.00 3sub  no      HFm3 trackmid3
*/
#include <string>
using namespace std;
namespace hi{

  enum EPNamesInd {
          HFm2,        HFp2,   trackmid2,       HFm2a,       HFp2a,
         HFm2b,       HFp2b,       HFm2c,       HFp2c,        HFm3,
          HFp3,   trackmid3,       HFm3a,       HFp3a,       HFm3b,
         HFp3b,       HFm3c,       HFp3c,   EPBLANK
  };

  const std::string  EPNames[]  = {
        "HFm2",      "HFp2", "trackmid2",     "HFm2a",     "HFp2a",
       "HFm2b",     "HFp2b",     "HFm2c",     "HFp2c",      "HFm3",
        "HFp3", "trackmid3",     "HFm3a",     "HFp3a",     "HFm3b",
       "HFp3b",     "HFm3c",     "HFp3c" 
  };

  enum Detectors {Tracker, HF, Castor};

  const int  EPDet[]  = {
          HF,        HF,   Tracker,        HF,        HF,
          HF,        HF,        HF,        HF,        HF,
          HF,   Tracker,        HF,        HF,        HF,
          HF,        HF,        HF 
  };

  const int  EPOrder[]  = {
             2,           2,           2,           2,           2,
             2,           2,           2,           2,           3,
             3,           3,           3,           3,           3,
             3,           3,           3 
  };

  const double  EPEtaMin1[]  = {
         -5.00,        3.00,       -0.75,       -5.00,        4.00,
         -4.00,        3.00,       -3.00,        2.00,       -5.00,
          3.00,       -0.75,       -5.00,        4.00,       -4.00,
          3.00,       -3.00,        2.00 
  };

  const double  EPEtaMax1[]  = {
         -3.00,        5.00,        0.75,       -4.00,        5.00,
         -3.00,        4.00,       -2.00,        3.00,       -3.00,
          5.00,        0.75,       -4.00,        5.00,       -3.00,
          4.00,       -2.00,        3.00 
  };

  const double  EPEtaMin2[]  = {
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00 
  };

  const double  EPEtaMax2[]  = {
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00 
  };

  const double  minTransverse[]  = {
          0.01,        0.01,        0.30,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.01,        0.01,
          0.01,        0.30,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01 
  };

  const double  maxTransverse[]  = {
         30.00,       30.00,        3.00,       30.00,       30.00,
         30.00,       30.00,       30.00,       30.00,       30.00,
         30.00,        3.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00 
  };

  const std::string  ResCalcType[]  = {
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub" 
  };

  const std::string  MomConsWeight[]  = {
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no" 
  };

  const int  RCMate1[]  = {
        HFp2,      HFm2,      HFm2,      HFp2,      HFm2,
        HFp2,      HFm2,      HFp2,      HFm2,      HFp3,
        HFm3,      HFm3,      HFp3,      HFm3,      HFp3,
        HFm3,      HFp3,      HFm3 
  };

  const int  RCMate2[]  = {
   trackmid2, trackmid2,      HFp2, trackmid2, trackmid2,
   trackmid2, trackmid2, trackmid2, trackmid2, trackmid3,
   trackmid3,      HFp3, trackmid3, trackmid3, trackmid3,
   trackmid3, trackmid3, trackmid3 
  };

  static const int NumEPNames = 18;
}
#endif
