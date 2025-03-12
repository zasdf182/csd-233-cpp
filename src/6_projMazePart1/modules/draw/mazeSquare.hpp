#ifndef MAZESQUARE_HPP
#define MAZESQUARE_HPP
#include <string>
#include "types/shapes.hpp"
#include "square.hpp"
namespace Draw {

////////////////////////////////////////////////////////////////////////////////
/// @brief Used in creating a Maze.
///        Extends a Square with methods for: ``` ```
///        - Removing sides. ``` ```
///        - Marking a square with a 'visited' or 'currently selected' symbol. ``` ```
////////////////////////////////////////////////////////////////////////////////
class MazeSquare : Square {
    public: //Static properties.
        static const int font = cv::FONT_HERSHEY_PLAIN;
        static constexpr double fontScale = 1.5;
        static const double charSize() {return 8 * fontScale;}
        static const char visitSymbol = 'v';
        static const char selectSymbol = 'q';
        static const int padding = 10;

    public: //Mutable properties.
        int eraseBlue;
        int eraseGreen;
        int eraseRed;

    private: //Encapsulated read-only properties.
        bool hasTop;
        bool hasRight;
        bool hasBottom;
        bool hasLeft;
        bool isVisited;
        bool isSelected;

    public: //Constructors and destructors
        MazeSquare(int x, int y, int width, int height, std::string wndname, cv::Mat raster):
            Square(x, y, width, height, wndname, raster),
            eraseBlue(0), eraseGreen(0), eraseRed(0),
            hasTop(true), hasRight(true), hasBottom(true), hasLeft(true),
            isVisited(false), isSelected(false) {};

    public: //OpenCV drawing methods.
        virtual void Draw();
        void RemoveSide(Side side);
        void MarkVisited();
        void MarkSelected();
        void MarkUnselected();

    public: //Getters for encapsulated read-only properties.
        bool const& HasTop() {return hasTop;}
        bool const& HasRight() {return hasRight;}
        bool const& HasBottom() {return hasBottom;}
        bool const& HasLeft() {return hasLeft;}
        bool const& IsVisited() {return isVisited;}
        bool const& IsSelected() {return isSelected;}
};
}
#endif
