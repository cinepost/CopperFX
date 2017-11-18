#ifndef __OP_NetworkBoxItem__
#define __OP_NetworkBoxItem__


class OP_NetworkBoxItem {
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