#include "include/Curve.h"
#include <iostream>
#include <numbers>
#include <algorithm>



int main() {
    std::unique_ptr<std::vector<std::unique_ptr<ICurve>>> curves = create_first_vector(); 
    
    print_curve_details(curves, std::numbers::pi_v<double> / 4);

		std::cout << "Размер вектора 1: "<< curves->size() << std::endl;
		
    auto circles = std::make_unique<std::vector<std::unique_ptr<ICurve>>>();
    move_circles_to_second_vector(curves, circles);
		std::cout << "Размер вектора 1, после перемещения всех кругов во второй вектор: "<< curves->size() << std::endl;
		
    std::sort(circles->begin(), circles->end(), [](const std::unique_ptr<ICurve>& a, const std::unique_ptr<ICurve>& b) {
        const Circle* circleA = dynamic_cast<const Circle*>(a.get());
        const Circle* circleB = dynamic_cast<const Circle*>(b.get());
        return circleA->getRadius() < circleB->getRadius();
    });

		std::cout << "Сумма всех радиусов кругов" << std::endl;
    std::cout << total_radii_sum_circles(circles) << std::endl;
    

    return 0;
}
