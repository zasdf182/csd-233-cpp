template <class T>
void Swap(T* obj1, T* obj2) {
    T data1 = *obj1;
    T data2 = *obj2;
    *obj1 = data2;
    *obj2 = data1;
}
