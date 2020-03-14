/**
 * Problem Source: 
 * https://leetcode.com/discuss/interview-question/396769/
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string T) {
  char a,b;
  string output;
  output = "";
  a = T[0];
  b = T[1];
  if(a == '?' && b == '?') output += "23";
  else if(a == '?') {
      if(b - '0' >= 4) output += "1" + T.substr(1,1);
      else output += "2" + T.substr(1,1);
          
  } else if(b == '?') {
      if(a == '2') output += T.substr(0,1) + "3";
      else output += T.substr(0,1) + "9";
  } else {
      output += T.substr(0,2);
  }
  output += ":";
  output += T[3] == '?' ? "5":T.substr(3,1);
  output += T[4] == '?' ? "9":T.substr(4,1);
  return output;
}

int main() {
  vector<string> T = {
      "06:34",
      "??:30",
      "?4:12",
      "?3:33",
      "1?:12",
      "2?:12",
      "13:??",
      "13:?8",
      "13:4?",
      "??:??",
      "?8:4?"
  };
  for(auto t : T) {
    cout << solution(t) << endl;
  }
  return 0;
}