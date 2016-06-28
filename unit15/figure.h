#ifndef FIGURE_H
#define FIGURE_H
class Figure {
public:
	Figure(double, double);
protected:
	double xSize, ySize;
};

class Figure_2D : public Figure {
public:
	Figure_2D(double, double);
	virtual double area() = 0;			//���������
	virtual double perimeter() = 0;		//���ܳ�����
};

class Figure_3D : public Figure_2D {
public:
	Figure_3D(double x,double y ,double z) : Figure_2D(x,y),zSize(z){}
	virtual double cubage() = 0;
protected:
	double zSize;
};

class Rectangle : public Figure_2D {
public:
	Rectangle(double, double);
	virtual double area();
	virtual double perimeter();
};

class Circle : public Figure_2D {
public:
	Circle(double, double);
	virtual double area();
	virtual double perimeter();
};

class Sphere : public Figure_3D {\
public:
	Sphere(double, double, double);
	virtual double cubage();
};
class Cone : public Figure_3D {
public:
	Cone(double, double, double);
	virtual double cubage();
};
#endif // !FIGURE_H

//2016��6��28��16:44:52
//ʵ����