#ifndef _COLOR_H_
#define _COLOR_H_

/** Color represents a color. */
class Color {
public:
	Color();

	/**
	 * Creates a new Color from the supplied color values.
	 * @param r - amount of red.
	 * @param g - amount of green.
	 * @param b - amount of blue.
	 */
	Color(unsigned char r, unsigned char g, unsigned char b);

	/** Assignment operator. */
	Color& operator= (const Color& other);


	void setColor(unsigned char r, unsigned char g , unsigned char b);
	
	unsigned char r() const { return _r; };
	unsigned char g() const { return _g; };
	unsigned char b() const { return _b; };

private:
	/** Each color component. */
	unsigned char _r, _g, _b;
};

#endif // _COLOR_H_