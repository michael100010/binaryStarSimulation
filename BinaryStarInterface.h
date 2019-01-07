#ifndef BINARY_STAR_INTERFACE
#define BINARY_STAR_INTERFACE

#include <string>

class BinaryStarInterface
{
	public:
		
		////////////////////////////
		//	Physical Element Methods
		////////////////////////////
		
		//	Returns the mass of the star in Suns. The solar mass (Suns) is a standard unit of mass in astronomy, equal to approximately 
		//	2×1030 kg. It is equal to the mass of the Sun.
		//	@pre	Star must be approximatly 1 solar mass (1 Sun).
		//	@param	The units of x are given in hours
		virtual double getPrimaryMass(unsigned short x) const = 0;
		virtual double getSecondaryMass(unsigned short x) const = 0;
		
		//	Returns the radius of the star in kilometers (unit symbol: km)
		//	@pre	star must be approximatly 1 solar mass (1 Sun).
		//	@param	The units of x are given in hours
		virtual double getPrimaryRadius(unsigned short x) const = 0;
		virtual double getSecondaryRadius(unsigned short x) const = 0;
		
		//	Returns the surface temperature of the star in kelvins (unit symbol: K). The kelvin is the base unit of temperature
		//  in the International System of Units (SI). 	Note that absolute zero (0 K) is equivalent to -273.15 °C (-459.67 °F), 
		//	which makes it an appropriate unit for astronomy.
		//	@pre	star must be approximatly 1 solar mass (1 sun).
		//	@param	The units of x are given in hours
		virtual double getPrimarySurfaceTemperature(unsigned short x) const = 0;
		virtual double getSecondarySurfaceTemperature(unsigned short x) const = 0;
		
		//	Returns the luminosity of the star in watts (unit symbol: W). In astronomy, luminosity is the total amount of energy
		//	emitted per unit of time by a star. In SI units luminosity is measured in watts (joules per second). 
		//	@pre	star must be approximatly 1 solar mass (1 Sun).
		//	@param	The units of x are given in hours
		virtual double getPrimaryLuminosity(unsigned short x) const = 0;
		virtual double getSecondaryLuminosity(unsigned short x) const = 0; //enter output data again
		
		//	Returns the Roche lobe radius of the star in kilometers (unit symbol: km). The Roche lobe is the region around a star 
		//	in a binary system within which orbiting material is gravitationally bound to that star. It is an approximately 
		//	tear-drop-shaped region bounded by a critical gravitational equipotential, with the apex of the tear drop pointing
		//	towards the other star (the apex is at the L1 Lagrangian point of the system).
		//	@pre	star must be approximatly 1 solar mass (1 Sun).
		virtual double getPrimaryRocheLobeRadius() const = 0; 	//stub
		virtual double getSecondaryRocheLobeRadius() const = 0;  //stub
		
		//	Returns the name of the star. Note that a primary is the main physical body of a gravitationally bound, multi-object
		//	system. This object constitutes most of that system's mass and will generally be located near the system's barycenter.
		//  For example, in the Solar System, the Sun is the primary for all objects that orbit the star.
		virtual std::string getPrimary() const = 0;
		virtual std::string getSecondary() const = 0;
		
		//	Returns the distance between the centers of the two stars in kilometers (unit symbol: km).
		//	This is used to calculate the barycenter.
		virtual double getDistance() const = 0;
		
		//	Returns the distance from the primary to the barycenter in kilometers (unit symbol: km). The barycenter is the center of mass 
		//	of two or more bodies that orbit each other and is the point about which the bodies orbit. If one of two orbiting bodies is 
		//	much more massive than the other and the bodies are relatively close to one another, the barycenter will typically be located 
		//	within the more massive object. In this case, rather than the two bodies appearing to orbit a point between them, the less 
		//	massive body will appear to orbit about the more massive body, while the more massive body might be observed to wobble slightly.
		//	When the two bodies are of similar masses, the barycenter will generally be located between them and both bodies will follow an 
		//	orbit around it. 
		//
		//	Let distance = The distance between the centers of the two starts given in kilometers,
		//	    primaryMass = The mass of the primary (more massive star) given in earth masses,
		//	    secondaryMass = The mass of the secondary (less massive star) given in earth masses, and
		//	    barycenter = The distance from the center of the primary to the barycenter given in kilometers.
		//
		//	The formula or the barycenter is given by,
		//	barycenter = distance * secondaryMass / (primaryMass + secondaryMass)
		//
		//	@param	distance given in km
		//	@param	primaryMass given in Suns
		//	@param	secondaryMass given in Suns
		virtual double getBarycenter(double distance, double primaryMass, double secondaryMass) const = 0;
		
		///////////////////////////
		//	Orbital Element Methods
		///////////////////////////
		
		//	Returns the semi-major axis of the star in kilometers (unit symbol: km). In geometry, the major axis of an ellipse is its 
		//	longest diameter: a line segment that runs through the center and both foci, with ends at the widest points of the perimeter. 
		//	The semi-major axis is one half of the major axis, and thus runs from the centre, through a focus, and to the perimeter. For 
		//	the special case of a circle, the semi-major axis is the radius.
		virtual double getSecondarySemiMajorAxis() const = 0;
		
		//	Returns the orbital period of the star in years. The orbital period is the time a given astronomical object takes to 
		//	complete one orbit around another object.
		virtual double getSecondaryOrbitalPeriod() const = 0;
		
		//	Returns the eccentricity of the star. Eccentricity describes how circular the orbit is. An Eccentricity value of 0 is a
		//	perfect circle. As the eccentricity value approaches 1, the orbit becomes more oblong. An eccentricity value greater than
		//	1 is a disconnected, hyperbolic orbit.  
		virtual float getSecondaryEccentricity() const = 0;
		
		//	Returns the inclination of the star in degrees. The inclination is the angle between the orbital plane and a reference plane.
		virtual float getSecondaryInclination() const = 0;
};

#endif
