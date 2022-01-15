#include "container.h"

using std::string;
using std::ifstream;
using std::ofstream;

// Инициализация контейнера.
container container::Initialize(int size) {
    container new_container;
    new_container.length = size;
    return new_container;
}

// Наполнение контейнера объектами из файла.
void container::Input(const string input_file) {
    ifstream file(input_file);
    for(int i=0; i<length; i++) {
        if(file.eof()) {
            break;
        }
        string first_word;
        int speed;
        double way_length;
        if(file >> first_word >> speed >> way_length) {
            if(first_word == "Plane") {
                int capacity, flight_radius;
                file >> capacity >> flight_radius;
                plane* new_plane = new plane(speed, way_length, capacity, flight_radius);
                pointer_arr[i] = new_plane;
            }
            if(first_word == "Train") {
                int wagon_number;
                file >> wagon_number;
                train* new_train = new train(speed, way_length, wagon_number);
                pointer_arr[i] =new_train;
            }
            if(first_word == "Ship") {
                int tonnage;
                int ship_type;
                file >> tonnage >> ship_type;
                if(ship_type == 1) {
                    ship* new_ship = new ship(speed, way_length, tonnage, LINER);
                    pointer_arr[i] = new_ship;
                }
                if(ship_type == 2) {
                    ship* new_ship = new ship(speed, way_length, tonnage, TUGBOAT);
                    pointer_arr[i] = new_ship;
                }
                if(ship_type == 3) {
                    ship* new_ship = new ship(speed, way_length, tonnage, TANKER);
                    pointer_arr[i] = new_ship;
                } else {
                    continue;
                }
            }
        }

    }
    file.close();
}

// Этот метод используется для записи информации о рандомно сгенерированном вводе.
// Таким образом рандомно сгенерированный ввод можно запустить уже в режиме чтения из файла.
void container::RawOutput(string input_file) {
    ofstream file;
    ofstream& file_ref = file;
    file.open(input_file);
    for(int i=0; i<length; i++) {
        pointer_arr[i]->RawOutput(file_ref);
    }
}

// Наполнение контейнера случайно сгенерированными объектами.
void container::InputRandom() {
    srand(time(nullptr));
    for(int i=0; i<length; i++) {
        int vehicle_type = rand() % 3;
        switch(vehicle_type) {
            case 0: {
                plane* new_plane = new plane();
                new_plane->plane::InputRandom();
                pointer_arr[i]=new_plane;
                break;
            }
            case 1: {
                train* new_train = new train();
                new_train->train::InputRandom();
                pointer_arr[i]=new_train;
                break;
            }
            case 2: {
                ship* new_ship = new ship();
                new_ship->ship::InputRandom();
                pointer_arr[i]=new_ship;
                break;
            }
        }
    }
}

// Подсчёт общей для всех альтернатив функции.
void container::CountCommonFunction() {
    for(int i=0; i<length; i++) {
        pointer_arr[i]->SimpleFunction();
    }
}

// Функция сортировки Binary Insertion Sort. Алгоритм аналогичен тому, что был в процедурном ДЗ.
void container::SortFunction(std::string output_file) {
    for(int i=1; i<length; ++i) {
        int j = i-1;
        double selected = pointer_arr[i]->GetIdealTime();
        int location = BinarySearchByTime(selected, 0, j);
        while(j>=location) {
            vehicle* temporary = pointer_arr[j+1];
            pointer_arr[j+1] = pointer_arr[j];
            pointer_arr[j] = temporary;
            j--;
        }
        pointer_arr[j+1]->SetIdealTime(selected);
    }
    ofstream file;
    ofstream& file_ref = file;
    file.open(output_file);
    for(int i=0; i<length; i++) {
        pointer_arr[i]->Output(file_ref);
        file << "\n";
    }
    file.close();
    return;
}

// Бинарный поиск.
int container::BinarySearchByTime(double selected, int low, int high) {
    while(low<=high) {
        int mid = low + (high - low) / 2;
        if(selected == pointer_arr[mid]->GetIdealTime()) {
            return mid+1;
        }
        if(selected > pointer_arr[mid]->GetIdealTime()) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}