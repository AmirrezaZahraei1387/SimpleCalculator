#include <iostream>
#include <limits>
#include <string_view>

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

double getNumber(){

    double number={};

    while (true){
    
        std::cout<<"enter a number:"<<std::endl;
        std::cin>>number;

        if (!std::cin){
            std::cin.clear();
            ignoreLine();
        }else{
            ignoreLine();
            return number;
        }
    }
}

char getOperatin(){

    char operation = {};

    while(true){
        
        std::cout<<"enter an operation"<<std::endl;
        std::cin>>operation;

        if (!std::cin){
            std::cin.clear();  
        }

        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation;
        default:
            std::cerr<<"the givven operation is not supported"<<std::endl;
            ignoreLine();
        }

    }

}

void calculateResult(double number_1, char operation, double number_2){

    switch (operation){
        case '+':
            std::cout<< number_1 + number_2<<std::endl;
            break;
        case '-':
            std::cout<< number_1 - number_2<<std::endl;
            break;
        case '*':
            std::cout<< number_1 * number_2<<std::endl;
            break;
        case '/':
            if (number_2 != 0.0)
                std::cout<< number_1 / number_2<<std::endl;
            else
                std::cerr<<"sorry, can't devide by zero";
            break;
    }
}

int main(){
    double number_1 = {getNumber()};
    double number_2 = {getNumber()};
    char operation = {getOperatin()};
    calculateResult(number_1, operation, number_2);
    return 0;
}