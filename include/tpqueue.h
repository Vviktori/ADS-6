// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>


template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
private:
    T* arr;
    int startIdx, endIdx, counter;

 public:
    TPQueue() : startIdx(0), endIdx(0), counter(0), arr(new T[size]) {}
    ~TPQueue() {
        delete[] arr;
    }
    void push(const T &elem) {
      if (counter >= size) {
        throw std::string("Error! Queue is full!");
      } else {
        if (counter == 0) {
          arr[startIdx] = elem;
          counter++;
        } else {
          endIdx++;
          int insIdx = endIdx;
          while (insIdx > startIdx && elem.prior > arr[(insIdx - 1) % size].prior) {
            arr[insIdx % size] = arr[(insIdx - 1) % size];
            insIdx--;
          }
          arr[insIdx % size] = elem;
          counter++;
        }
      }
    }
    T pop() {
      if (counter == 0) {
        throw std::string("Error! Queue is empty!");
      } else {
        counter--;
        T popped = arr[startIdx];
        startIdx = (startIdx + 1) % size;
        return popped;
      }
    }
};


struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
