#ifndef Vector_h
#define Vector_h
#define MAX_RADIUS 10
/*
*Represent a mathematical Vector
*/
class Vector{
	
	private:
		short _degree;
		char _radius;
		float _x,_y;
		
		/*Calculates the x and y coordinates with the degree and radius*/
		void calculate();
		
	public:
		/*Cretes a null vector*/
		Vector();
		
		/*Creates a vector with the given degree and radian*/
		Vector(short degree, char radius);
		/*Calculates the distance to the given vector*/
		float getDistance(Vector* v);
		
		void setDegree(short degree);
		void setRadius(char radius);
		float x() const{ return _x; }
		float y() const{ return _y; }
        short getDegree() const { return _degree; }
        char getRadius() const { return _radius; }
		
};

#endif
