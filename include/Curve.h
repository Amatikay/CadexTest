#ifndef CURVE_H
#define CURVE_H

#include <vector>
#include <cmath>
#include <memory>
#include <iostream>

struct Point {
    double x = {};
    double y = {};
    double z = {};
};

class ICurve {
public:
	virtual Point getPoint(const double& t) = 0;
	virtual Point getDerivative (const double& t) = 0;
	// virtual double getRadius () = 0;
	virtual ~ICurve () = default;
	
};

class Circle : public ICurve {
public:
	Circle() {};
	Circle(const double& p_radius);
	Point getPoint(const double& t) override;
	Point getDerivative(const double& t) override;
	double getRadius() const {return radius;};
private:
	double radius = {};
};

class Ellipse : public ICurve {
public:
	Ellipse(const double& p_radi_a, const double& p_radi_b);
	Ellipse() {};
	Point getPoint (const double& t) override;
	Point getDerivative(const double& t) override;
private:
	double radi_a = {};
	double radi_b = {};
};

class Helix : public ICurve {
public:
	Helix(const double& p_radius, const double& p_step);	
	Helix() {};
	Point getPoint (const double& t) override;
	Point getDerivative(const double& t) override;
private:
	double radius = {};
	double step = {};
};

std::unique_ptr<std::vector<std::unique_ptr<ICurve>>> create_first_vector ();

void move_circles_to_second_vector (
const std::unique_ptr<std::vector<std::unique_ptr<ICurve>>>& curves,
const std::unique_ptr<std::vector<std::unique_ptr<ICurve>>>& circles);
double total_radii_sum_circles(const std::unique_ptr<std::vector<std::unique_ptr<ICurve>>>& circles);

template<typename T>
void print_curve_details(const std::unique_ptr<std::vector<std::unique_ptr<ICurve>>>& curves,T t_point) {
	std::cout << "--Вывести координаты каждой кривой и производной в точке t = pi /4--" << std::endl;
	for(auto& curve : *curves){

		if      (typeid(*curve) == typeid(Circle))
			std::cout << "Круг" << std::endl;
		else if (typeid(*curve) == typeid(Ellipse))
			std::cout << "Эллипс" << std::endl;
		else if (typeid(*curve) == typeid(Helix))
			std::cout << "Спираль" << std::endl;
	
		std::cout << "\nТочка" << std::endl;
		std::cout << "x: "   << curve->getPoint(t_point).x << 
								 "\ty: " << curve->getPoint(t_point).y <<
								 "\tz: " << curve->getPoint(t_point).z <<  std::endl;
								 
		std::cout << "Производная" << std::endl;
		std::cout << "x: "   << curve->getDerivative(t_point).x << 
								 "\ty: " << curve->getDerivative(t_point).y << 
								 "\tz: " << curve->getDerivative(t_point).z <<  std::endl;
		std::cout << "\n" << std::endl;
	}
};

#endif
