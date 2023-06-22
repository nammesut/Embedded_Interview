#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> array;

    array.push_back(2);
    array.push_back(4);
    array.pop_back();
    array.insert(array.begin() + 1, 77);

    for(int i = 0; i<array.size();i++){
        printf("%d\n", array[i]);
    }
    return 0;
}
