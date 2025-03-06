#include <iostream>
using namespace std;




////////////////////////////////////////////////////////////////////////////////
class MyCharString {
    public: //Mutable properties.
        char* bufP;

    private: //Encapsulated read-only properties.
        int size;
    public:
        int Size() {return size;}
        int Size() const {return size;}

    public: //Constructors and destructors.
        MyCharString(string s) {
            size = s.length();
            bufP = new char[size + 1];
            for (int i = 0; i <= size; i++)
                bufP[i] = s[i];
        }
        MyCharString(MyCharString const& original) {
            size = original.Size();
            bufP = new char[size + 1];
            for (int i = 0; i <= size; i++)
                bufP[i] = original.bufP[i];
        }
        ~MyCharString() {
            // Test deallocations.
            cout << endl << "ms with address of first buffer char " << (void*) bufP << " was deleted.";
            delete[] bufP;
            bufP = nullptr;
            cout << " The new buffer value is nullptr.";
            cout << " The new address of first buffer char is " << (void*) bufP << ".";
        }

    public: //Query methods.
        void display() {
            cout << bufP;
        }

    public: //Operator overloads.
        MyCharString operator=(MyCharString const& obj) {
            delete[] this->bufP;
            this->size = obj.Size();
            this->bufP = new char[size + 1];
            for (int i = 0; i <= size; i++)
                this->bufP[i] = obj.bufP[i];
            return *this;
        }
};



////////////////////////////////////////////////////////////////////////////////
MyCharString f(string s) {
    MyCharString ms1(s);
    {
        MyCharString ms2 = ms1;
    }
    return ms1;
}




////////////////////////////////////////////////////////////////////////////////
int main() {
    // string s = "Sandy";
    // MyCharString v = f(s);
    // v.display();

    // Add print statements to track that pointers are not used after they are freed
    // and that all allocations are deleted prior to completing the main function.
    cout << endl;
    cout << endl;
    {
        cout << endl << "Creating ms3 and ms4 using string constructor.";
        MyCharString ms3("message3");
        MyCharString ms4("message4");
        cout << endl << "ms3 address of first char in buffer: " << (void*) ms3.bufP;
        cout << endl << "ms3 buffer value: " << ms3.bufP;
        cout << endl << "ms4 address of first char in buffer: " << (void*) ms4.bufP;
        cout << endl << "ms4 buffer value: " << ms4.bufP;
        cout << endl;

        // Test operator overload.
        cout << endl << "Assigning ms3 = ms4.";
        ms3 = ms4;
        cout << endl << "ms3 new address of first char in buffer: " << (void*) ms3.bufP;
        cout << endl << "ms3 new buffer value: " << ms3.bufP;
        cout << endl;

        // Test copy constructor.
        cout << endl << "Creating ms5 using copy constructor on ms4";
        MyCharString ms5(ms4);
        cout << endl << "ms5 address of first char in buffer: " << (void*) ms5.bufP;
        cout << endl << "ms5 buffer value: " << ms5.bufP;
        cout << endl;
    }
    cout << endl;
    cout << endl;
}
