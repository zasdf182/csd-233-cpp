#include <iostream>
#include <vector>
#include <cstdlib>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;




/**
 * Uses OpenCV to render and update a live screen of pixels.
 *
 * Maintains one protected OpenCV::Mat (matrix) of pixels.
 * The Mat is unsigned, 8-bit, 3 channels (BGR - Blue Green Red).
 *
 * Has public functions for drawing shapes.
 * Maintains one protected vector of shape definitions.
 * Every time the vector is updated, it recalculates shape sizes and positions.
 * Shape sizes and positions are randomized but are guaranteed to fit on screen.
 * Shape color fills are also randomized.
 * Then, it redraws the entire screen with the new shapes.
 *
 * TODO: Add public functions for updating text in a pre-determined textbox.
 */
class Screen {

        // ################################################################## //
        // ############################## ENUMS ############################# //
        // ################################################################## //

    public:
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

    protected:
        /** Unsigned 8-bit BGR matrix. */
        Mat _mat;
        /** Universally unique id used to create unique GUI windows.  */
        string _uuid;
        /**
         * A container of all shapes this screen should be displaying.
         * The screen is automatically redrawn every time this is updated.
         */
        vector<Shape> _shapes;




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
         */
        Screen(int width, int height) {
            // Keep track of screen size for future shape calculations.
            _width = width;
            _height = height;
            // Allocate memory.
            _mat = Mat(Size(width, height), CV_8UC3);
            _shapes = vector<Shape>();
            // Init GUI window.
            Clear();
            imshow(_uuid, _mat);
        }

        /**
         * Destructor that deallocates memory and destroys the GUI window.
         */
        ~Screen() {
            // Deallocate memory.
            _mat.release();
            // Destroy GUI window.
            destroyWindow(_uuid);
        }




        // ################################################################## //
        // ######################### DRAWING METHODS ######################## //
        // ################################################################## //

    public:
        /**
         * Adds a new shape to be rendered.
         * @param type One of: circle ellipse rectangle triangle line
         */
        void AddShape(const char* type) {
            char* shape = new char[strlen(type)];
            strcpy(shape, type);
            string shapeStr = string(shape);
            if (shapeStr == "circle") _shapes.push_back(CIRCLE);
            else if (shapeStr == "ellipse") _shapes.push_back(ELLIPSE);
            else if (shapeStr == "rectangle") _shapes.push_back(RECTANGLE);
            else if (shapeStr == "triangle") _shapes.push_back(TRIANGLE);
            else if (shapeStr == "line") _shapes.push_back(LINE);
            delete[] shape;
        }

    private:
        /**
         * Fills matrix with black pixels.
         */
        void Clear() {
            _mat = Scalar(0, 0, 0);
        }

        /**
         * Updates the screen to have all shapes in _shapes.
         */
        void UpdateRender() {
            // First, reset to black screen.
            Clear();

            // Limit shape sizes based on number of shapes, to fit on screen.
            int shapeCount = _shapes.size();
            int maxShapeWidth = _width / shapeCount;
            int maxShapeHeight = _height / shapeCount;

            // Draw each shape with random properties.
            for (int i = 0; i < shapeCount; i++) {
                Shape shape = _shapes[i];

                // Get bounding box, equally dividing screen for each shape.
                int rectLeft = maxShapeWidth * i;
                int rectRight = maxShapeWidth * (i + 1);
                int rectTop = maxShapeHeight * i;
                int rectBottom = maxShapeHeight * (i + 1);

                // Get random color.
                int randomBlue = rand() % 255;
                int randomGreen = rand() % 255;
                int randomRed = rand() % 255;
                Scalar randomColor = Scalar(randomBlue, randomGreen, randomRed);

                // Get random size and position within unique bounding box.
                // Each shape specifies position and size in different ways.
                if (shape == CIRCLE) {

                    // Circle needs center point and radius.
                    Point randomCenter;
                    int randomRadius;

                    // Calculate random center point.
                    int randomCenterX = rand() % rectRight + rectLeft;
                    int randomCenterY = rand() % rectBottom + rectTop;
                    randomCenter = Point(randomCenterX, randomCenterY);

                    // Calculate random radius.
                    int maxRadiusX = min(
                                         abs(rectRight - randomCenterX),
                                         abs(rectLeft - randomCenterX)
                                     );
                    int maxRadiusY = min(
                                         abs(rectTop - randomCenterY),
                                         abs(rectBottom - randomCenterY)
                                     );
                    int maxRadius = min(maxRadiusX, maxRadiusY);
                    randomRadius = rand() % maxRadius;

                    // Draw circle.
                    circle(
                        _mat,
                        randomCenter,
                        randomRadius,
                        randomColor,
                        FILLED
                    );

                }

                // Ellipse needs:
                // - center point
                // - major axis length
                // - minor axis length
                // - angle of rotation in anti-clockwise direction
                // -
                else if (shape == ELLIPSE) {



                } else if (shape == RECTANGLE) {

                } else if (shape == TRIANGLE) {

                } else if (shape == LINE) {

                }
            }

            // Finally, render new shapes to GUI window.
            imshow(_uuid, _mat);
        }




        // ################################################################## //
        // ########################## HELPER METHODS ######################## //
        // ################################################################## //

    private:
        /**
        * Change all chars in a char array to lowercase.
        */
        void ToLower(char* charArray) {
            int charCount = strlen(charArray);
            for (int i = 0; i < charCount; i++)
                charArray[i] = tolower(charArray[i]);
        }
};
