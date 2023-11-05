#include <iostream>
#include <map>
#include <tuple>

class SparseMatrix {
private:
    std::map<std::pair<int, int>, int> elements;
    int rows, cols;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void addElement(int row, int col, int value) {
        if (value != 0) {
            elements[std::make_pair(row, col)] = value;
        }
    }

    void displaySparse() {
        std::cout << "Sparse Matrix Representation:\n";
        for (const auto& element : elements) {
            std::cout << "Row: " << element.first.first
                      << ", Column: " << element.first.second
                      << ", Value: " << element.second << "\n";
        }
    }

    void displayFullMatrix() {
        std::cout << "Full Matrix Representation:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                auto it = elements.find(std::make_pair(i, j));
                if (it != elements.end()) {
                    std::cout << it->second << " ";
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << "\n";
        }
    }
};

int main() {
    SparseMatrix sm(4, 5);

    // Add different non-zero elements
    sm.addElement(0, 1, 1);
    sm.addElement(0, 4, 2);
    sm.addElement(1, 2, 8);
    sm.addElement(2, 0, 9);
    sm.addElement(2, 3, 3);
    sm.addElement(3, 4, 7);

    sm.displaySparse();
    std::cout << "\n";
    sm.displayFullMatrix();

    return 0;
}
