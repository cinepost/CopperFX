#ifndef NETWORK_BOX_ITEM_H
#define NETWORK_BOX_ITEM_H


namespace copper {

class NetworkBoxItem {
	public:
		float	getX();
		float	getY();
		void	setX(float x);
		void	setY(float y);

	private:
		float	_x;
		float	_y;
};

}

#endif // NETWORK_BOX_ITEM_H