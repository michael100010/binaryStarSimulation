#ifndef LOW_MASS_XRAY_BINARY
#define	LOW_MASS_XRAY_BINARY

#include "BinaryStarInterface.h"
#include <cmath>

class LowMassXrayBinary : public BinaryStarInterface
{
	private:
		
	////////////////////////////
	//	Physical Element Members
	////////////////////////////
	
	//	The members below are listed for completion.
	//	They are commented out in order to avoid stale data.
	//	The class methods will generate the member data
	//  over the lifetime of the object.
	//
	//	double primaryMass;
	//	double secondaryMass;
	//
	//	double primaryRadius;
	//	double secondaryRadius;
	//
	//	double primarySurfaceTemperature;
	//	double secondarySurfaceTemperature;
	//
	//	double primaryLuminosity;
	//	double secondaryLuminosity;
	//
	//	double primaryRocheLobeRadius;
	//	double secondaryRocheLobeRadius;
		
		std::string primary;
		std::string secondary;
		
		double distance;
	
	//	The member below is listed for completion.
	//	It is commented out in order to avoid stale data.
	//	The class method will generate the member data
	//  over the lifetime of the object.
	//
	//	double barycenter;
		
	///////////////////////////
	//	Orbital Element Members
	///////////////////////////
		
		double secondarySemiMajorAxis;
		
		double secondaryOrbitalPeriod;
		
		float secondaryEccentricity;
		
		float secondaryInclination;
		
	public:
	
	////////////////
	//	Constructors
	////////////////
		
		LowMassXrayBinary();
		
		//	@param	primary is the name of the more massive star
		//	@param	secondary is the name of the less massive star
		//	@param	secondaryEccentricity values range from 0 to 1
		//	@param	secondaryInclination values are given in degrees
		//	@param	distance values are given in kilometers
		LowMassXrayBinary(std::string primary, std::string secondary, double distance,
						  double secondarySemiMajorAxis, float secondaryEccentricity, float secondaryInclination);
							
							
	////////////////////////////
	//	Physical Element Methods
	////////////////////////////
		
		double getPrimaryMass(unsigned short x) const
		{ return 1.7988834*pow(10, -5)*pow(x, 2) - .0079446323*x + 1.151121251;	};
		double getSecondaryMass(unsigned short x) const
		{ return .9360949096*pow(x, .0437529247); };
		
		double getPrimaryRadius(unsigned short x) const
		{ return 43.31097561*x + 17871412.07; };
		double getSecondaryRadius(unsigned short x) const
		{ return -9.357078*pow(10, -6)*pow(x, 2) + .0041635146*x + 2.983160572; };
		
		double getPrimarySurfaceTemperature(unsigned short x) const
		{ return 4290;};
		double getSecondarySurfaceTemperature(unsigned short x) const
		{ return 2.7; };
		
		double getPrimaryLuminosity(unsigned short x) const
		{ return 7.511238*pow(10, 28); };
		double getSecondaryLuminosity(unsigned short x) const
		{ return 0;	};
		
		double getPrimaryRocheLobeRadius() const {};	//stub
      	double getSecondaryRocheLobeRadius() const {};  //stub
		
		std::string getPrimary() const { return primary; };
		std::string getSecondary() const { return secondary; };
		
		double getDistance() const { return distance; };
		double getBarycenter(double distance, double primaryMass, double secondaryMass) const;
		
	///////////////////////////
	//	Orbital Element Methods
	///////////////////////////
				 
		double getSecondarySemiMajorAxis() const { return secondarySemiMajorAxis; };
		 
		double getSecondaryOrbitalPeriod() const { return secondaryOrbitalPeriod; };
		 
		float getSecondaryEccentricity() const { return secondaryEccentricity; };
		 
		float getSecondaryInclination() const { return secondaryInclination; };		
};

#endif
