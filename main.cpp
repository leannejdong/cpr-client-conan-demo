#include <cpr/cpr.h>
#include <iostream>
#include <future>
#include <vector>

int main(int argc, char** argv) {

  //Option1: Asynchronous response : handle the response at some later time
  std::vector<std::future<cpr::Response>> responses;
  auto url = cpr::Url{"https://httpbin.org/get"};
  for(int i{0}; i < 1000; ++i){
    responses.emplace_back(cpr::GetAsync(url));
  }
  for(auto& r : responses){
    std::cout << r.get().text << "\n";
  }

  //Option2: Asynchronous callbacks
  auto future = cpr::GetCallback([](cpr::Response r){
    return r.text;
  }, cpr::Url{"https://httpbin.org/get"});
  std::cout << future.get() << "\n";

}

