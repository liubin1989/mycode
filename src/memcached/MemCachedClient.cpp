#include<iostream>
#include"MemCachedClient.h"
using std::cout;
using std::endl;

int main()
{
    MemCachedClient mc;
    cout<<"Hello World\n"<<endl;
    mc.Insert("kingcat","value123");     
    cout << mc.Get("kingcat") << endl;
    return 1;
}