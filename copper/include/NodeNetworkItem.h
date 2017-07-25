#ifndef __NodeNetworkItem__
#define __NodeNetworkItem__


class NodeNetworkItem {
	public:
		float	getX();
		float	getY();
		void	setX(float x);
		void	setY(float y);

	private:
		float	x;
		float	y;
};

#endif