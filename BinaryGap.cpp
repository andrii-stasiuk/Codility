// 1. BinaryGap [Task Score: 100%] [Correctness: 100%] [Performance: Not assessed]
// Find longest sequence of zeros in binary representation of an integer
// https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
#include <vector>
int solution(int N) {
  vector <int> A;
  // Converts Integer to a vector of Binaries
  int iter = 0;
  while (N > 0) {
    A.insert(A.begin(), N % 2); // A.push_back(N % 2);
    N = N / 2;
    iter++;
  }
  // Searching for the greatest match of binary gap '10...01'
  int resTemp = 0;
  int resFinal = 0;
  for (unsigned int i = 1; i < A.size(); i++) {
    int j = 0;
    if (A[i - 1] == 1)
      while (A[i + j] == 0) {
        j++;
      }
    if ((j > 0) && (A[i + j - 1] == 0) && (A[i + j] == 1)) {
      resTemp = j;
      if (resTemp > resFinal) resFinal = resTemp;
    }
  }
  // for(unsigned int i=0; i<A.size(); ++i)
  //   std::cout << A[i] << ' ';
  return resFinal;
}
