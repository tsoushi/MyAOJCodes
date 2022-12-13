#include <stdio.h>

int main() {
    int n, k;
    int w[100000];

    scanf("%d %d", &n, &k);
    int totalWeight = 0;
    int maxWeight = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        totalWeight += w[i];
        if (w[i] > maxWeight) maxWeight = w[i];
    }

    // (合計重量 / トラックの数) と (重量の最大値)のうち大きい方をトラックの最大積載量の初期値としてとる
    int weightLimitPerTruck = totalWeight / k > maxWeight ? totalWeight / k : maxWeight;
    // 最大積載量を1ずつ増やしていき、荷物を全部積み込めるまで試行する
    while (1) {
        int i;
        int weight = 0; // 現在積載中の重量
        int truckCount = 0; // 積載済みトラック数
        for (i = 0; i < n; i++) {
            if (weight + w[i] > weightLimitPerTruck) {
                // 重量オーバーで積み込めなかった場合
                truckCount++;
                weight = 0;
                if (truckCount >= k) break; // この時点でトラックを全部使い切っていたら失敗
            }
            weight += w[i]; // 荷物を積み込み
        }
        if (i != n) {
            // 荷物を全て積み込めていなかったら
            weightLimitPerTruck++; // 最大積載量を1増やして再試行
        } else {
            break;
        }
    }

    printf("%d\n", weightLimitPerTruck);

    return 0;
}