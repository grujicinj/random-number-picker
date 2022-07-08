#include <iostream>
#include <random>

int split(int max, int pieces) {
    int total = 0;
    int blocktot = 0;

    int from = 0;

    for (int i = 0; i < pieces; i++) {
        if (blocktot >= max) {
            blocktot = max;
        }

        from = max / (i + 1) - blocktot / (i + 1);

        if (i == 0) {
            from = 1;
        }else if(i == pieces - 1) {
            from = max - blocktot;
        }

        int to = max - blocktot;
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(from, to);

        total = distr(generator);

        blocktot = blocktot + total;

        std::cout << "Iteration: " << i << " Starting at: " << from << " Ending at: " << to << " With result of: " << total << " In block: " << blocktot << std::endl;
    }

    return blocktot;
}

int main(){
    int x = 0, y = 0;

    std::cout << "Number? ";
    std::cin >> x;
    std::cout << "Pieces? ";
    std::cin >> y;

    std::cout << split(x, y);

    return 0;
}
