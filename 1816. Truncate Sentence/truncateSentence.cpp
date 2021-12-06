#include <string>

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int l=0;
          for(int i=0;i<s.length();i++)

          { 
            if(s[i]==' ')l++;//如果遇到空格截取的就加一壹；
             if(l==k){s=s.substr(0,i);break;}//过的时候没加break，算个小优化吧，算吧，算吧
          }
         //如果截取不到，肯定就是跑完了，s还是你的s，不用变

          return s;
    }
};

int main() {}