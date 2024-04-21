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
    void push(const T &elem) {
      int insertIdx;
      if (counter >= size) {
        throw std::string("Error! Queue is full!");
      } else {
        if (counter == 0) {
          arr[startIdx] = elem;
          counter++;
        } else {
          endIdx ++;
          for (insertIdx = endIdx; insertIdx >= startIdx; insertIdx--) {
            if (elem.prior > arr[(insertIdx - 1) % size].prior) {
              arr[insertIdx % size] = arr[(insertIdx - 1) % size];
            } else {
              break;
            }
          }
          arr[insertIdx % size] = elem;
          counter++;
        }
      }
    }
    T pop() {
      if (counter == 0) {
        throw std::string("Error! Queue is empty!");
      } else {
        counter--;
        return arr[startIdx++ % size];
      }
    }  
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
