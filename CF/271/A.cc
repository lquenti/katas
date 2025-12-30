#include<iostream>
int x;
int a,b,c,d;
int i;

int main() {
  std::cin >> x;
  for (;i=x+1;++x) {
    //std::cout << x << std::endl;
    a=i%10;i/=10;
    b=i%10;i/=10;
    c=i%10;i/=10;
    d=i%10;
    if (a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d) {
      std::cout << d << c << b << a << std::endl;
      return 0;
    }
  }
}
