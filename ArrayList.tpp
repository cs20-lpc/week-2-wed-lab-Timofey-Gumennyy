template <typename T>
ArrayList<T>::ArrayList(int i) {
    // TODO
    this->buffer = new T[i];
    this->maxSize = i;
    this->length = 0;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    clear();
}

template <typename T>
void ArrayList<T>::append(const T& elem) {
    // TODO
    if (this->length == this->maxSize) {
        throw string("append: error, list is full");
    }
    this->buffer[this->length] = elem;
    this->length++;
}

template <typename T>
void ArrayList<T>::clear() {
    // TODO
    this->length = 0;
}

template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& copyObj) {
    // TODO
    this->buffer = new T[copyObj.maxSize];
    this->maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    for (int i = 0; i < this->length; i++) {
        this->buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
T ArrayList<T>::getElement(int position) const {
    // TODO
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    return this->buffer[position];
}

template <typename T>
int ArrayList<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayList<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    // TODO
    if (position < 0 || position > this->length) {
        throw string("insert: error, position out of bounds");
    }
    if (this->length == this->maxSize) {
        throw string("insert: error, list is full");
    }
    this->length++;
    for (int i = this->length - 1; i > position; i--) {
        this->buffer[i] = this->buffer[i - 1];
    }
    this->buffer[position] = elem;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
void ArrayList<T>::remove(int position) {
    // TODO
    if (position < 0 || position >= this->length) {
        throw string("remove: error, position out of bounds");
    }
    for (int i = position; i < this->length - 1; i++) {
        this->buffer[i] = this->buffer[i + 1];
    }
    this->length--;
}

template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    // TODO
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }
    this->buffer[position] = elem;

}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        for (int i = 0; i < myObj.length; i++) {
            outStream << myObj.buffer[i] << ' ';
        }
        outStream << endl;
    }

    return outStream;
}
