#ifndef NETWORK_BOX_ITEM_H
#define NETWORK_BOX_ITEM_H


namespace copper {

class NetworkBoxItem {
	public:
		NetworkBoxItem();

	public:
		float	x();
		float	y();
		void	setX(float x);
		void	setY(float y);

	private:
		float	_x;
		float	_y;
};

}

#endif // NETWORK_BOX_ITEM_H