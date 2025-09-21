#include <iostream>
#include "../include/hw1/main.h"

int main(int argc, char **argv)
{
    int i, n;

    std::cout << "몇 개의 원소를 할당하겠습니까? : ";
    std::cin >> i;

    std::cout << "정수형 데이터 입력:";
    std::cin >> n;

    dohyun::Numbers numbers(i, n);

    for (int j = 1; j < i; j++)
    {
        std::cout << "정수형 데이터 입력:";
        std::cin >> n;
        numbers.set(j, n);
    }
    std::cout << "최대값: " << numbers.get_max() << std::endl;
    std::cout << "최소값: " << numbers.get_min() << std::endl;
    std::cout << "전체합: " << numbers.get_sum() << std::endl;
    std::cout << "평 균: " << (double)numbers.get_sum() / i << std::endl;

    return 0;
}