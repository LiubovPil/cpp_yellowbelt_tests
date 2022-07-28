// WeightsBlocks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int64_t WeightCalculation(int& W, int& H, int& D, int& R) {
    int64_t weight = 0;
    weight = static_cast<uint64_t> (W)* H* D* R;
    return weight;
}

int main()
{
    int N; 
    int R;
    cin >> N >> R;

    int64_t total_weight = 0;

    for (int i = 0; i < N; ++i) {
        int W, H, D;
        cin >> W >> H >> D;
        total_weight += WeightCalculation(W, H, D, R);
    }

    cout << "Total weight of all blocks - " << total_weight;
}