#ifndef CATACLYSMIC_VARIABLE
#define CATACLYSMIC_VARIABLE

#include "BinaryStarInterface.h"
#include <cmath>

class CataclysmicVariable : public BinaryStarInterface
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
		
		CataclysmicVariable();
		
		//	@param	primary is the name of the more massive star
		//	@param	secondary is the name of the less massive star
		//	@param	secondaryEccentricity values range from 0 to 1
		//	@param	secondaryInclination values are given in degrees
		//	@param	distance values are given in kilometers
		CataclysmicVariable(std::string primary, std::string secondary, double distance,
							double secondarySemiMajorAxis, float secondaryEccentricity, float secondaryInclination);
							
							
	////////////////////////////
	//	Physical Element Methods
	////////////////////////////
		
		double getPrimaryMass(unsigned short x) const
		{ return -8.649326*pow(10, -8)*pow(x, 3) + 5.3399051*pow(10, -5)*pow(x, 2) - .0103415836*x + 1.195859237; };
		double getSecondaryMass(unsigned short x) const
		{ return -2.735277*pow(10, -6)*pow(x, 2) + .0010974075*x + 1.000174434; };
		
		double getPrimaryRadius(unsigned short x) const
		{ return .1389260636*pow(x, 2) - 29.19566437*x + 17875322.04; };
		double getSecondaryRadius(unsigned short x) const
		{ return -2.09035*pow(10, -4)*pow(x, 3) + .1295173386*pow(x, 2) - 25.32947169*x + 6171.448295; };
		
		double getPrimarySurfaceTemperature(unsigned short x) const
		{ return 4290; };
		double getSecondarySurfaceTemperature(unsigned short x) const
		{ return 4.7121627*pow(10, -4)*pow(x, 3) - .2672697835*pow(x, 2) + 46.8610422*x + 19216.95325; };
		
		double getPrimaryLuminosity(unsigned short x) const
		{ return 7.51*pow(10, 28); };
		double getSecondaryLuminosity(unsigned short x) const
		{ return -4.849864*pow(10, 14)*pow(x, 4) + 3.6112087*pow(10, 17)*pow(x, 3) - 9.834628*pow(10, 19)*pow(x, 2) 
				 + 1.2090254*pow(10, 22)*x + 3.9604709*pow(10, 24); };
		
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

