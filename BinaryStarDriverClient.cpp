#include "CataclysmicVariable.h"
#include "LowMassXrayBinary.h"
#include <iostream>
#include <iomanip>
#include <memory>


void orbitalElementDisplay(std::shared_ptr<BinaryStarInterface> binaryStar);

void physicalElementDisplay(std::shared_ptr<BinaryStarInterface> binaryStar);

int main()
{
	std::shared_ptr<CataclysmicVariable> CV = 
	std::make_shared<CataclysmicVariable>("Arcturus", "Sirius B", 19017629.31, 19017629.313, 0.0, 0.0);
	
	std::shared_ptr<LowMassXrayBinary> LMXB = 
	std::make_shared<LowMassXrayBinary>("Arcturus", "Black hole", 19172607.41, 19147829.265, .029, 0.0);
	
	std::cout << "Displaying orbital elements for the cataclysmic variable\n\n";
	orbitalElementDisplay(CV);
	
	std::cout << "Press the enter key to continue";
	std::cin.get();
	std::system("cls");
	
	std::cout << "Displaying orbital elements for the low-mass x-ray binary\n\n";
	orbitalElementDisplay(LMXB);
	
	std::cout << "Press the enter key to continue";
	std::cin.get();
	std::system("cls");
	
	std::cout << "Displaying physical elements for the cataclysmic variable\n\n";
	physicalElementDisplay(CV);
		
	std::cout << "Press the enter key to continue";
	std::cin.get();
	std::system("cls");
	
	std::cout << "Displaying physical elements for the low-mass x-ray binary\n\n";
	physicalElementDisplay(LMXB);
	
	return 0;
}

void orbitalElementDisplay(std::shared_ptr<BinaryStarInterface> binaryStar)
{
	std::cout << std::setw(12) << std::left << "Name" << "|" << std::setw(18) << std::left << "Semi-Major Axis" 
			  << "|" << std::setw(16) << std::left << "Orbital Period" << "|" << std::setw(14) << std::left 
			  << "Eccentricity" << "|" << std::setw(13) << std::left << "Inclination" << std::endl
			  << "---------------------------------------------------------------------------" << std::endl
			  << std::setw(12) << std::left << binaryStar->getSecondary() << "|" << std::setw(18) << std::left
			  << std::setprecision(11) << binaryStar->getSecondarySemiMajorAxis() << "|" << std::setw(16) 
			  << std::left << std::setprecision(3) << binaryStar->getSecondaryOrbitalPeriod() << "|" 
			  << std::setw(14) << std::left << std::setprecision(2) << binaryStar->getSecondaryEccentricity() 
			  << "|" << std::setw(13) << std::left << std::setprecision(2) <<binaryStar->getSecondaryInclination() 
			  << std::endl << std::endl;
}

void physicalElementDisplay(std::shared_ptr<BinaryStarInterface> binaryStar)
{				  
	//The following displays mass and radius data for the primary and secondary star
	for (int hour = 1; hour <= 310; ++hour)
	{
	 	std::cout << std::setw(12) << std::left << "Name" << "|" << std::setw(6) << std::left << "Hour" << "|" 
	 			  << std::setw(8) << std::left << "Mass" << "|" << std::setw(10) << std::left << "Radius" << std::endl
				  << "--------------------------------------" << std::endl
				  << std::setw(12) << std::left << binaryStar->getPrimary() << "|" << std::setw(6) << std::left
				  << hour << "|" << std::setw(8) << std::left << std::setprecision(4) << binaryStar->getPrimaryMass(hour)
				  << "|" << std::setw(10) << std::left << std::setprecision(8) << binaryStar->getPrimaryRadius(hour) << std::endl
				  << "--------------------------------------" << std::endl
				  << std::setw(12) << std::left << binaryStar->getSecondary() << "|" << std::setw(6) << std::left
				  << hour << "|" << std::setw(8) << std::left << std::setprecision(4) << binaryStar->getSecondaryMass(hour)
				  << "|" << std::setw(10) << std::left << std::setprecision(8) << binaryStar->getSecondaryRadius(hour) 
				  << std::endl << std::endl;
				
		if (hour % 49 == 0)
		{
			std::cout << "Press the enter key to continue";
			std::cin.get();
			std::system("cls");
		}	
	}
	
	std::cout << "Press the enter key to continue";
	std::cin.get();
	std::system("cls");
	
	//The following displays surface temperature and luminosity data for the primary and secondary star
	for (int hour = 1; hour <= 310; ++hour)
	{
		std::cout << std::setw(12) << std::left << "Name" << "|" << std::setw(6) << std::left << "Hour" << "|" 
				  << std::setw(21) << std::left << "Surface Temperature" << "|" << std::setw(12) << std::left
				  << "Luminosity" << std::endl
				  << "-------------------------------------------------------" << std::endl
				  << std::setw(12) << std::left << binaryStar->getPrimary() << "|" << std::setw(6) << std::left 
				  << hour << "|" << std::setw(21) << std::left << std::setprecision(8) 
				  << binaryStar->getPrimarySurfaceTemperature(hour) << "|" << std::setw(12) << std::left 
				  << std::setprecision(7) << binaryStar->getPrimaryLuminosity(hour) << std::endl 
				  << "-------------------------------------------------------" << std::endl
				  << std::setw(12) << std::left << binaryStar->getSecondary() << "|" << std::setw(6) << std::left
				  << hour << "|" << std::setw(21) << std::left << std::setprecision(8) << binaryStar->getSecondarySurfaceTemperature(hour)
				  << "|" << std::setw(12) << std::left << std::setprecision(3) << binaryStar->getSecondaryLuminosity(hour) 
				  << std::endl << std::endl;
				  
		if (hour % 49 == 0)
		{
			std::cout << "Press the enter key to continue";
			std::cin.get();
			std::system("cls");
		}	
	}
	
	std::cout << "Press the enter key to continue";
	std::cin.get();
	std::system("cls");
	
	
	//The following displays the barycenter distance
	for (int hour = 1; hour <= 310; ++hour)
	{
		std::cout << std::setw(12) << std::left << "Name" << "|" << std::setw(6) << std::left << "Hour" << "|" 
				  << std::setw(8) << std::left << "Mass" << "|" << std::setw(13) << std::left << "Barycenter" << std::endl
				  << "----------------------------------------" << std::endl
				  << std::setw(12) << std::left << binaryStar->getPrimary() << "|" << std::setw(6) << std::left << hour << "|" 
				  << std::setw(8) << std::left << std::setprecision(4) << binaryStar->getPrimaryMass(hour) << "|" 
				  << std::setw(13) << std::left << std::setprecision(10) 
				  << binaryStar->getBarycenter(binaryStar->getDistance(), binaryStar->getPrimaryMass(hour), binaryStar->getSecondaryMass(hour))
				  << std::endl
				  << "----------------------------------------" << std::endl
				  << std::setw(12) << std::left << binaryStar->getSecondary() << "|" << std::setw(6) << std::left << hour << "|"
				  << std::setw(8) << std::left << std::setprecision(4) << binaryStar->getSecondaryMass(hour) << "|" << std::endl << std::endl;
					  
		if (hour % 48 == 0)
		{
			std::cout << "Press the enter key to continue";
			std::cin.get();
			std::system("cls");
		}	
	}	
}

