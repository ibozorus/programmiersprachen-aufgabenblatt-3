#ifndef BUW_STACK_HPP
#define BUW_STACK_HPP
#include <vector>
#include <stdexcept>

namespace buw {
  template<typename T>
  class Stack {
  public:
    Stack() = default;

    void push(T const& value) {
      data_.push_back(value);
    }

    void pop() {
      if (!data_.empty()) {
        data_.pop_back();
      }
    }

    T top() const {
      if (data_.empty()) {
        throw std::out_of_range{ "Stack is empty!" };
      }
      return data_.back();
    }

    bool empty() const {
      return data_.empty();
    }

    std::size_t size() const {
      return data_.size();
    }

  private:
    std::vector<T> data_;
  };
}
#endif // BUW_STACK_HPP
