
#include <iostream>
#include <chrono>

double calculate(int iterations, double param1, double param2) {
  double result = 1.0;
  for (int i = 1; i <= iterations; ++i) {              
    double j = i * param1 - param2;             
    result -= (1 / j);                          
    j = i * param1 + param2;                  
    result += (1 / j);                           
  }
  return result;
}

int main() {
  const int iterations = 200'000'000;
  const double param1 = 4.0, param2 = 1.0;   

  auto start = std::chrono::high_resolution_clock::now();
  double result = calculate(iterations, param1, param2) * 4;  
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed = end - start;      

  std::cout << "Result: " << result << std::endl;    
  std::cout << "Execution Time: " << elapsed.count() << " seconds" << std::endl;   

  return 0;
}
