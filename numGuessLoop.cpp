// Copyright (c) 2022 Sarah All rights reserved.
//
// Created by: Sarah
// Created on: Apr, 25, 2022.
// This program asks the user to  guess a number. It then generates a
// random number. It then checks to see if userNum is the same as rand_num. If
// it is, it breaks out of the loop. If not, it keeps going, it uses a while
// true loop.

#include <iostream>
#include <random>

int main() {
    // Generates random number
    int randomNumber;
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,100]
    randomNumber = idist(rgen);
    // std::cout << randomNumber << std::endl;

    // declare variable
    int userNum;
    int counter = 0;
    std::string userNumString;

    while (true) {
        // get number guessed from user
        std::cout << "Enter a number between 0 and 9: ";
        std::cin >> userNumString;
        std::cout << "" << std::endl;

        // convert from string to int
       try {
         userNum = std::stoi(userNumString);

           // sets a range
            if (userNum >= 0 && userNum <= 9) {
        // check if userNum is the same as randomNumber. It then displays the
        // results.
                if (userNum == randomNumber) {
                    std::cout << std::endl;
                    std::cout << userNum << " is the correct guess!";
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << userNum << " is incorrect. Try again.\n";
                    std::cout << std::endl;
                    std::cout << "Tracking ";
                    std::cout << counter << " times through loop.\n";
                    counter = counter + 1;
                    std::cout << std::endl;
                }
            } else {
           std::cout << "Please enter a number within the range.\n";
           }
        // handling any possible errors.
       } catch (std::invalid_argument) {
            std::cout << userNumString << " is not a number.\n";
       }
    }
}
