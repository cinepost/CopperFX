#ifndef __NetworkBoxItem__
#define __NetworkBoxItem__


class NetworkBoxItem {
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