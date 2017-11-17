#ifndef __UT_Vector2_h__
#define __UT_Vector2_h__

#include <vector>
#include <stdexcept>
#include <math.h>

class UT_Vector2 {
	public:
		Vector2(const Vector2 &vec); // copy constructor
		Vector2():_comps{0.0, 0.0} {};
		Vector2(double x, double y):_comps{x, y} {};
		Vector2(std::vector<double> &comps);

		void set(double x, double y);
		void set(std::vector<double> &comps);

		//calculate and return the magnitude of this vector
		double length();

		//calculate and return the squared magnitude of this vector
		double lengthSquared();

		//build and return normalized vector
		Vector2 normalized();

		//calculate and return distance between two vectors
		double distance(Vector2 &vec);

		//overloaded operators
		double &operator[](int index);
		const double &operator[](int index) const;
		bool operator==(const Vector2& vec);

	private:
		double _comps[2];
		
};

#endif