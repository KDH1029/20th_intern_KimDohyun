#include <iostream>
#include <random>
#include <cmath>

#include "../include/hw2/main.h"

int main(int argc, char **argv)
{
    int i, min, max;

    std::cout << "******** HW 3 Point Distance Computation ********"
              << std::endl
              << std::endl
              << std::endl
              << std::endl
              << "Please define the number of points: ";
    std::cin >> i;
    dohyun::Points points(i);

    std::cout << "Please define minimum of coor. value: ";
    std::cin >> min;
    std::cout << "Please define maximum of coor. value: ";
    std::cin >> max;

    std::cout << std::endl
              << std::endl
              << "Generate Random points" << std::endl;

    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::uniform_int_distribution<> rand(min, max);

    for (int j = 0; j < i; j++)
    {
        int x = rand(mersenne);
        int y = rand(mersenne);
        points.set_x(j, x);
        points.set_y(j, y);
        std::cout << "Point " << j + 1 << ". nX=" << x << " , nY=" << y << std::endl;
    }

    for (int j = 0; j < i; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            points.dist(j, k);
        }
    }

    std::cout << std::endl
              << "-------- Result --------" << std::endl
              << "MinDist =" << sqrt(points.get_min()) << std::endl
              << "Pair of Min Coor.<x,y>: P1<" << points.get_x(points.get_min(0)) << "," << points.get_y(points.get_min(0)) << "> & P2<" << points.get_x(points.get_min(1)) << "," << points.get_y(points.get_min(1)) << ">" << std::endl
              << std::endl
              << "MaxDist =" << sqrt(points.get_max()) << std::endl
              << "Pair of Max Coor.<x,y>: P1<" << points.get_x(points.get_max(0)) << "," << points.get_y(points.get_max(0)) << "> & P2<" << points.get_x(points.get_max(1)) << "," << points.get_y(points.get_max(1)) << ">" << std::endl
              << std::endl
              << std::endl
              << "***************** Completed *****************"
              << std::endl
              << std::endl
              << std::endl;
}