// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    T arr[size];
    int startIdx, endIdx, counter;

 public:
    TPQueue() : startIdx(-1), endIdx(-1) {}

    bool empty() {
      return startIdx == -1;
    }

    bool full() {
      return (startIdx == 0 && endIdx == size - 1) || (startIdx == endIdx + 1);     
    }
    
    void push (const T &elem) {
      if (full()) {
        throw std::string ("Queue overflow!");
        return;
      }
      if (empty()) {
        startIdx = endIdx = 0;
      } else {
        int insertIdx = endIdx;
        while (insertIdx >= startIdx && elem.prior > arr[insertIdx].prior) {
          arr[insertIdx + 1] = arr[insertIdx];
          insertIdx--;
        }
        endIdx++;
      }
      arr[endIdx] = elem;
    }
    T pop() {
      if (empty()) {
        throw std::string ("Queue underflow");
      }
      T elem = arr[startIdx];
      if (startIdx == endIdx) {
        startIdx = endIdx = -1;
      } else {
        startIdx++;
      }
      return elem;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
