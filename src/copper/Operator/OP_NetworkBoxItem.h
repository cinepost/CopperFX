#ifndef NETWORK_BOX_ITEM
#define NETWORK_BOX_ITEM


namespace copper {

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

}

#endif // NETWORK_BOX_ITEM