#ifndef TIME_MIGRATOR_3D_H
#define TIME_MIGRATOR_3D_H

#include "tmigratorBase.h"

class TimeMigrator3D : public TimeMigratorBase {

public:

	    TimeMigrator3D ();
	   ~TimeMigrator3D ();

	void  processGather (Point2D& curGatherCoords, float curOffset,  const float* const velTrace, const bool isAzDip,
								  float* curoffsetGather, float* curoffsetImage, float* curoffsetImageSq);

private:

	int   getSampleByBeam        (const float yCIG, const float xCIG, const float curZeroTime, 
	  				 			  const float curDip, const float curAz, const float migVel, const bool isAzDip, float& sample);

	float getSampleByRay         (const float yCIG, const float xCIG, const float curZeroTime, 
					              const float curDip, const float curAz, const float migVel, const bool isAzDip,
					              const float yEmAngle, const float xEmAngle);

	float getSampleFromData		 (const float geoY, const float geoX, const float ti, const float p);
};
#endif
