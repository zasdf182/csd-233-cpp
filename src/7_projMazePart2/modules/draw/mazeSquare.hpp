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
        static constexpr double fontScale = 0.75;
        static const double charSize() {return 8 * fontScale;}
        static const char visitSymbol = 'v';
        static const char selectSymbol = 'q';
        static const char pathSymbol = 'o';
        static const char deadSymbol = 'x';
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
        bool isPathed;
        bool isDead;

    public: //Static methods.
        static const Side Opposite(Side side);

    public: //Constructors and destructors.
        MazeSquare(int x, int y, int width, int height, std::string wndName, cv::Mat raster):
            Square(x, y, width, height, wndName, raster),
            eraseBlue(0), eraseGreen(0), eraseRed(0),
            hasTop(true), hasRight(true), hasBottom(true), hasLeft(true),
            isVisited(false), isSelected(false) {};

    public: //OpenCV drawing methods.
        virtual void Draw();
        void RemoveSide(Side side);
        void MarkVisited();
        void MarkSelected();
        void MarkPathed();
        void MarkDead();
        void UnmarkVisited();
        void UnmarkSelected();
        void UnmarkPathed();
        void UnmarkDead();

    public: //Getters for encapsulated read-only properties.
        bool const& HasTop() {return hasTop;}
        bool const& HasRight() {return hasRight;}
        bool const& HasBottom() {return hasBottom;}
        bool const& HasLeft() {return hasLeft;}
        bool const& IsVisited() {return isVisited;}
        bool const& IsSelected() {return isSelected;}
        bool const& IsPathed() {return isPathed;}
        bool const& IsDead() {return isDead;}
        bool const& HasTop() const {return hasTop;}
        bool const& HasRight() const {return hasRight;}
        bool const& HasBottom() const {return hasBottom;}
        bool const& HasLeft() const {return hasLeft;}
        bool const& IsVisited() const {return isVisited;}
        bool const& IsSelected() const {return isSelected;}
        bool const& IsPathed() const {return isPathed;}
        bool const& IsDead() const {return isDead;}
};
}
#endif
