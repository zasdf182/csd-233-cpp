#include <random>
#include <iostream>
#include "tree.cpp"
#include "treeNode.cpp"

int main() {
    int numbers[1000];
    int removedNumbers[10];
    Collections::Tree<int> tree;
    srand(42);

    // Test code that exercises the class by adding a list of sequential random numbers.
    // Create an array of 1000 integers.
    for (int i = 0; i < 1000; i++)
        numbers[i] = i;

    // Randomize the array by swapping values in the array.
    for (int i = 0; i < 1000; i++) {
        int randomIndex = rand() % 1000;
        int num1 = numbers[i];
        int num2 = numbers[randomIndex];
        numbers[i] = num2;
        numbers[randomIndex] = num1;
    }

    // Insert all the numbers into the binary tree.
    for (int i = 0; i < 1000; i++)
        tree.AddItem(numbers[i]);

    // Search for each number, and make sure each number is found.
    for (int i = 0; i < 1000; i++) {
        bool found = tree.FindItem(numbers[i]);
        if (!found)
            std::cout << std::endl << "TEST FAILED: " << i << " was not found!";
    }

    // Remove 10 random numbers
    for (int i = 0; i < 10; i++) {
        int randomIndex = rand() % 1000;
        int randomRemovedNumber = numbers[randomIndex];
        removedNumbers[i] = randomRemovedNumber;
        tree.RemoveItem(randomRemovedNumber);
    }

    // Do an in-order-traversal verifying that each number 0...999 is found except for the 10 that were removed.
}
