#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <random>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
namespace DRAW {




/**
 * Uses OpenCV to render and update a live screen of pixels.
 *
 * Maintains one protected OpenCV::Mat (matrix) of pixels.
 * The Mat is unsigned, 8-bit, 3 channels (BGR - Blue Green Red).
 *
 * Call AddShape() to prepare a shape to be drawn.
 * After preparing all the desired shapes, the user should call Render()
 * to draw all of the shapes and update the screen.
 *
 * Shape sizes and positions are randomized but are guaranteed to fit on screen.
 * Shape color fills are also randomized.
 *
 * TODO: Add public functions for updating text in a pre-determined textbox.
 */




class Screen {

        // ################################################################## //
        // ############################## TYPES ############################# //
        // ################################################################## //

    public:
        /** A pointer to a function that draws a Shape on a Screen. */
        typedef void (Screen::*DrawFuncPtr)(cv::Scalar, int boundLeft, int boundRight, int boundTop, int boundBottom);
        /** An enum used to tell the Screen which shapes to draw. */
        enum Shape {
            CIRCLE,
            ELLIPSE,
            RECTANGLE,
            TRIANGLE,
            LINE
        };




        // ################################################################## //
        // ############################ PROPERTIES ########################## //
        // ################################################################## //

    private:
        /** Screen width. */
        int _width;
        /** Screen height. */
        int _height;
        /** Max number of shapes allowed. Set in constructor. */
        int _maxShapeCount;
        /** Current number of shapes in _shapes array. */
        int _shapeCount;

    protected:
        /** Unsigned 8-bit BGR matrix. */
        cv::Mat _mat;
        /** Universally unique id used to create unique GUI windows.  */
        string _uuid;
        /** An array of shapes that should be drawn when Render() is called. */
        Shape* _shapes;
        /** Maps strings to Shape enum. */
        map<string, Shape> _shapeNames;
        /** An array of function pointers, one for each shape draw function. */
        DrawFuncPtr* _drawFuncPtrs;




        // ################################################################## //
        // ################### CONSTRUCTORS AND DESTRUCTORS ################# //
        // ################################################################## //
    public:

        /**
         * Constructor that allocates needed memory and creates a GUI window.
         * @param width The width of the GUI window.
         * @param height The height of the GUI window.
         * @param uuid A universally unique id.
         *             If creating multiple Screens in the same program,
         *             use different uuids for each.
         * @param maxShapes The maximum number of shapes allowed on the screen.
         */
        Screen(int width, int height, string uuid, int maxShapes) {
            // Init private properties.
            _width = width;
            _height = height;
            _maxShapeCount = maxShapes;
            _shapeCount = 0;
            _uuid = uuid;
            _mat = cv::Mat(cv::Size(width, height), CV_8UC3);
            _shapes = new Shape[maxShapes];
            // Map shapes to drawing functions.
            _shapeNames.insert(pair<string, Shape>("circle", Shape::CIRCLE));
            _shapeNames.insert(pair<string, Shape>("ellipse", Shape::ELLIPSE));
            _shapeNames.insert(pair<string, Shape>("rectangle", Shape::RECTANGLE));
            _shapeNames.insert(pair<string, Shape>("triangle", Shape::TRIANGLE));
            _shapeNames.insert(pair<string, Shape>("line", Shape::LINE));
            // Fill array of function pointers for shape draw functions.
            _drawFuncPtrs = new DrawFuncPtr[5];
            *(_drawFuncPtrs + Shape::CIRCLE) = &Screen::DrawCircle;
            *(_drawFuncPtrs + Shape::ELLIPSE) = &Screen::DrawEllipse;
            *(_drawFuncPtrs + Shape::RECTANGLE) = &Screen::DrawRectangle;
            *(_drawFuncPtrs + Shape::TRIANGLE) = &Screen::DrawTriangle;
            *(_drawFuncPtrs + Shape::LINE) = &Screen::DrawLine;
            // Init GUI window.
            Clear();
            cv::imshow(_uuid, _mat);
        }

        /**
         * Destructor that deallocates memory and destroys the GUI window.
         */
        ~Screen() {
            // Deallocate memory.
            _mat.release();
            delete[] _shapes;
            delete[] _drawFuncPtrs;
            // Destroy GUI window.
            cv::destroyWindow(_uuid);
        }




        // ################################################################## //
        // ##################### PUBLIC DRAWING METHODS ##################### //
        // ################################################################## //
    public:

        /**
         * An alternative to calling AddShape() then Render().
         * Takes a variable number of arguments and calls AddShape() for each.
         * Then, calls Render() at the end.
         */
        void displayShapes(int count, ...) {
            va_list args;
            va_start(args, count);
            for (int i = 0; i < count; i++)
                AddShape(va_arg(args, char*));
            va_end(args);
            Render();
        }

        /**
         * Prepares a new shape to be drawn.
         * NOTE: After adding all the desired shapes, call Render() to draw them all at once.
         * @param type One of: circle ellipse rectangle triangle line (case insensitive)
         */
        void AddShape(char* type) {
            char* typeLower = ToLower(type);
            string s(typeLower);
            map<string, Shape>::iterator it = _shapeNames.find(s);

            // Check for errors
            if (_shapeCount >= _maxShapeCount) {
                cout << endl << "ERROR: Cant add shape. Already at max shapes." << endl;
                return;
            }
            if (it == _shapeNames.end()) {
                cout << endl << "ERROR: Tried to add incorrect shape type" << endl;
                return;
            }

            // Add shape
            *(_shapes + _shapeCount) = (it->second);
            _shapeCount++;

            // Deallocate memory
            delete[] typeLower;
        }

        /**
         * Clears the screen,
         * then draws all shapes by calling all functions in _shapeDrawFuncs,
         * then renders the screen.
         */
        void Render() {
            // First, reset to black screen.
            Clear();

            // Fit shapes in a grid.
            int maxCols = ceil(sqrt(_shapeCount));
            int maxRows = ceil(sqrt(_shapeCount));
            int maxShapeWidth = _width / maxCols;
            int maxShapeHeight = _height / maxRows;

            // Draw each shape with random properties.
            for (int i = 0; i < _shapeCount; i++) {

                // Get random color.
                int randomBlue = rand() % 255;
                int randomGreen = rand() % 255;
                int randomRed = rand() % 255;
                cv::Scalar randomColor = cv::Scalar(randomBlue, randomGreen, randomRed);

                // Get bounding box, equally dividing screen for each shape.
                int boundLeft = maxShapeWidth * (i % maxRows);
                int boundRight = maxShapeWidth * ((i % maxRows) + 1);
                int boundTop = maxShapeHeight * (i / maxCols);
                int boundBottom = maxShapeHeight * ((i / maxCols) + 1);

                // Draw shape using array of function pointers.
                Shape shape = *(_shapes + i);
                (this->**(_drawFuncPtrs + shape))(randomColor, boundLeft, boundRight, boundTop, boundBottom);
                imshow(_uuid, _mat);

                // Pause for 4 seconds with waitKey()
                cv::waitKey(4000);
            }
        }




        // ################################################################## //
        // ##################### PRIVATE DRAWING METHODS #################### //
        // ################################################################## //
    private:

        /**
         * Fills matrix with black pixels.
         */
        void Clear() {
            _mat = cv::Scalar(0, 0, 0);
        }

        /**
         * Draws a circle with the given fill color.
         * It will have a random size and position within the given bounding box.
         */
        void DrawCircle(cv::Scalar color, int boundLeft, int boundRight, int boundTop, int boundBottom) {
            cv::Point randomCenter = RandomPoint(boundLeft, boundRight, boundTop, boundBottom);
            int maxRadius = GetMinorAxis(randomCenter, boundLeft, boundRight, boundTop, boundBottom);
            int randomRadius = RandomRange((maxRadius / 2), maxRadius);
            cv::circle(_mat, randomCenter, randomRadius, color, cv::FILLED);
        }

        /**
         * Draws an ellipse with the given fill color.
         * It will have a random size and position within the given Rect.
         */
        void DrawEllipse(cv::Scalar color, int boundLeft, int boundRight, int boundTop, int boundBottom) {
            cv::Point randomCenter = RandomPoint(boundLeft, boundRight, boundTop, boundBottom);
            int maxMajorAxis = GetMajorAxis(randomCenter, boundLeft, boundRight, boundTop, boundBottom);
            int maxMinorAxis = GetMinorAxis(randomCenter, boundLeft, boundRight, boundTop, boundBottom);
            int randomMajorAxis = RandomRange((maxMajorAxis / 2), maxMajorAxis);
            int randomMinorAxis = RandomRange((maxMinorAxis / 2), maxMinorAxis);
            int horizontalAxis = GetHorizontalAxis(randomCenter, boundLeft, boundRight, boundTop, boundBottom);
            int verticalAxis = GetVerticalAxis(randomCenter, boundLeft, boundRight, boundTop, boundBottom);
            cv::Size axes(randomMajorAxis, randomMinorAxis);
            double angle = 0;
            if (verticalAxis > horizontalAxis)
                angle = 180;
            double fillAngleStart = 0;
            double fillAngleEnd = 360;
            cv::ellipse(_mat, randomCenter, axes, angle, fillAngleStart, fillAngleEnd, color, cv::FILLED);
        }

        /**
         * Draws a rectangle with the given fill color.
         * It will have a random size and position within the given Rect.
         */
        void DrawRectangle(cv::Scalar color, int boundLeft, int boundRight, int boundTop, int boundBottom) {
            cv::Point randomCenter = RandomPoint(boundLeft, boundRight, boundTop, boundBottom);
            int maxHorizontalAxis = GetHorizontalAxis(randomCenter, boundLeft, boundRight, boundTop, boundBottom);
            int maxVerticalAxis = GetVerticalAxis(randomCenter, boundLeft, boundRight, boundTop, boundBottom);
            int randomHorizontalAxis = RandomRange((maxHorizontalAxis / 2), maxHorizontalAxis);
            int randomVerticalAxis = RandomRange((maxVerticalAxis / 2), maxVerticalAxis);
            cv::Point topLeft(randomCenter.x - randomHorizontalAxis, randomCenter.y - randomVerticalAxis);
            cv::Point bottomRight(randomCenter.x + randomHorizontalAxis, randomCenter.y + randomVerticalAxis);
            cv::rectangle(_mat, topLeft, bottomRight, color, cv::FILLED);
        }

        /**
         * Draws a triangle with the given fill color.
         * It will have a random size and position within the given Rect.
         */
        void DrawTriangle(cv::Scalar color, int boundLeft, int boundRight, int boundTop, int boundBottom) {
            cv::Point* randomPoints = new cv::Point[3];
            *(randomPoints + 0) = RandomPoint(boundLeft, boundRight, boundTop, boundBottom);
            *(randomPoints + 1) = RandomPoint(boundLeft, boundRight, boundTop, boundBottom);
            *(randomPoints + 2) = RandomPoint(boundLeft, boundRight, boundTop, boundBottom);
            cv::fillConvexPoly(_mat, randomPoints, 3, color);
            delete[] randomPoints;
        }

        /**
         * Draws a line with the given fill color.
         * It will have a random size and position within the given Rect.
         */
        void DrawLine(cv::Scalar color, int boundLeft, int boundRight, int boundTop, int boundBottom) {
            int randomThickness = RandomRange(4, 16);
            int margin = randomThickness + 1;
            int bl = boundLeft + margin;
            int br = boundRight - margin;
            int bt = boundTop + margin;
            int bb = boundBottom - margin;
            cv::Point randomPoint1 = RandomPoint(bl, br, bt, bb);
            cv::Point randomPoint2 = RandomPoint(bl, br, bt, bb);
            cv::line(_mat, randomPoint1, randomPoint2, color, randomThickness);
        }




        // ################################################################## //
        // ##################### PRIVATE HELPER METHODS ##################### //
        // ################################################################## //
    private:

        /**
        * Returns a new lowercase char array.
        * Does not mutate original char array.
        * NOTE: Remember to delete the new char array later.
        */
        char* ToLower(char* charArray) {
            int charCount = strlen(charArray);
            char* buffer = new char[charCount + 1];
            char* cursor1 = buffer;
            char* cursor2 = charArray;
            for (int i = 0; i < charCount; i++) {
                *cursor1 = tolower(*cursor2);
                cursor1++;
                cursor2++;
            }
            *cursor1 = '\0';
            return buffer;
        }

        /**
         * Generates a random int within a range (inclusive min and max).
         */
        int RandomRange(int min, int max) {

            return (rand() % (max - min)) + min;
        }

        /**
         * Generates a random point within a bounding box.
         */
        cv::Point RandomPoint(int boundLeft, int boundRight, int boundTop, int boundBottom) {
            int x = RandomRange(boundLeft, boundRight);
            int y = RandomRange(boundTop, boundBottom);
            return cv::Point(x, y);
        }

        /**
         * Get the minor axis length of an ellipse that fits exactly within a bounding box.
         */
        int GetMinorAxis(cv::Point center, int boundLeft, int boundRight, int boundTop, int boundBottom) {
            int x = min(abs(boundRight - center.x), abs(boundLeft - center.x));
            int y = min(abs(boundTop - center.y), abs(boundBottom - center.y));
            return min(x, y);
        }

        /**
         * Get the major axis length of an ellipse that fits exactly within a bounding box.
         */
        int GetMajorAxis(cv::Point center, int boundLeft, int boundRight, int boundTop, int boundBottom) {
            int x = min(abs(boundRight - center.x), abs(boundLeft - center.x));
            int y = min(abs(boundTop - center.y), abs(boundBottom - center.y));
            return max(x, y);
        }

        /**
         * Get the horizontal axis length of an ellipse that fits exactly within a bounding box.
         */
        int GetHorizontalAxis(cv::Point center, int boundLeft, int boundRight, int boundTop, int boundBottom) {
            return min(abs(boundRight - center.x), abs(boundLeft - center.x));
        }

        /**
         * Get the vertical axis length of an ellipse that fits exactly within a bounding box.
         */
        int GetVerticalAxis(cv::Point center, int boundLeft, int boundRight, int boundTop, int boundBottom) {
            return min(abs(boundTop - center.y), abs(boundBottom - center.y));
        }
};
}
