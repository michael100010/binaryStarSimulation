#include "LowMassXrayBinary.h"
#include <cmath>
#include <iostream>
#include <iomanip>

////////////////
//	Constructors
////////////////

LowMassXrayBinary::LowMassXrayBinary() : primary(""), secondary(""), distance(0),
										 secondarySemiMajorAxis(0), secondaryOrbitalPeriod(0),
										 secondaryEccentricity(0), secondaryInclination(0)
{
	
}

LowMassXrayBinary::LowMassXrayBinary(std::string primary, std::string secondary, double distance,
									 double secondarySemiMajorAxis, float secondaryEccentricity, float secondaryInclination)
{
	this->primary = primary;
	this->secondary = secondary;
	
	this->secondarySemiMajorAxis = secondarySemiMajorAxis;
	
	//	Converting the units of the semi-major axis (km) to astronomical units (AU).
	//  Conversion factor is 1 AU / (1.496 * 10^8 km)
	double convertedSecondarySemiMajorAxis = secondarySemiMajorAxis * 1 / (1.496 * pow(10, 8));
	
	//	Using Kepler’s Third Law to calculate the orbit’s period from its semi-major axis. 
	//	The Law states that the square of the period is equal to the cube of the semi-major 
	//	axis (p^2 = a^3). In order for the units to be correct, the semi-major axis should 
	//	be in astronomical units, and the period should be in years.
	double pSquared = pow(convertedSecondarySemiMajorAxis, 3);
	
	double p = sqrt(pSquared);
	secondaryOrbitalPeriod = p;
	
	this->secondaryEccentricity = secondaryEccentricity;
	
	this->secondaryInclination = secondaryInclination;	
	
	this->distance = distance;
}

////////////////////////////
//	Physical Element Methods
////////////////////////////

double LowMassXrayBinary::getBarycenter(double distance, double primaryMass, double secondaryMass) const
{
	//	Converting the units of star mass in solar mass (Suns) to earth mass (Earths)
	//	Conversion factor is 1 Earth / (2.99 * 10^-6)
	double convertedPrimaryMass = primaryMass * 1 / (2.99 * pow(10.0, -6.0));
	double convertedSecondaryMass = secondaryMass * 1 / (2.99 * pow(10.0, -6.0));
	return distance * convertedSecondaryMass / (convertedPrimaryMass + convertedSecondaryMass);
}
