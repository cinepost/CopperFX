#ifndef __Vector3_h__
#define __Vector3_h__

#include <vector>
#include <stdexcept>

class Vector3 {
	public:
		Vector3():_comps{0.0, 0.0, 0.0} {};
		Vector3(std::vector<double> &comps);

		double x();
		double y();
		double z();
		void setTo(double x, double y, double z);
		void setTo(std::vector<double> &comps);

		double &operator[](int index);

	private:
		double _comps[3];
		
};

#endif