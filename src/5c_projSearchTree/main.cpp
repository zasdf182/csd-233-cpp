#include <random>
#include <iostream>
#include "tree.cpp"
#include "treeNode.cpp"

int main() {
    // Test code that exercises the class by adding a list of sequential random numbers.
    // Create an array of 1000 integers.
    int numbers[1000];
    for (int i = 0; i < 1000; i++)
        numbers[i] = i;

    // Randomize the array by swapping values in the array.
    srand(42);
    for (int i = 0; i < 1000; i++) {
        int randomIndex = rand() % 1000;
        int num1 = numbers[i];
        int num2 = numbers[randomIndex];
        numbers[i] = num2;
        numbers[randomIndex] = num1;
    }

    // Insert all the numbers into the binary tree.
    Collections::Tree<int> tree;
    for (int i = 0; i < 1000; i++)
        tree.AddItem(i);

    // Search for each number, and make sure each number is found.
    for (int i = 0; i < 1000; i++) {
        bool found = tree.FindItem(i);
        if (!found)
            std::cout << std::endl << "TEST FAILED: " << i << " was not found!";
    }
}
