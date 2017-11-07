#ifndef __Vector3_h__
#define __Vector3_h__

#include <vector>
#include <stdexcept>
#include <math.h>

class Vector3 {
	public:
		Vector3(const Vector3 &vec);  // copy constructor
		Vector3():_comps{0.0, 0.0, 0.0} {};
		Vector3(double x):_comps{x, x, x} {};
		Vector3(double x, double y, double z):_comps{x, y, z} {};
		Vector3(std::vector<double> &comps);

		void set(double x, double y, double z);
		void set(std::vector<double> &comps);

		//calculate and return the magnitude of this vector
		double length();

		//calculate and return the squared magnitude of this vector
		double lengthSquared();

		//build and return normalized vector
		Vector3 normalized();

		//calculate and return distance between two vectors
		double distance(Vector3 &vec);

		//overloaded operators
		double &operator[](int index);
		const double &operator[](int index) const;
		bool operator==(const Vector3& vec);

	private:
		double _comps[3];
		
};

#endif