#include <stdio.h>
#include <string.h>
#include <ctime>
#include <cstdlib>
#pragma warning(disable: 4996)

class Player {
    int card[3];
    char name[100];
public:
    Player() {
        strcpy(name, "플레이어");
    }

    Player(const char* name) {
        strcpy(this->name, name);
    }

    const char* getName() {
        return name;
    }

    bool playGambling();
};

bool Player::playGambling() {
    printf("\t");
    for (int i = 0; i < 3; i++) {
        card[i] = rand() % 3;
        printf("\t%d", card[i]);
    }

    for (int i = 0; i < 2; i++) {
        if (card[i] != card[i + 1]) {
            return false;
        }
    }
    return true;
}

class GamblingGame {
    Player player[2];
    bool isGameEnd = false;
public:
    GamblingGame();
    void play();
};

GamblingGame::GamblingGame() {
    printf("***** 갬블링 게임을 시작합니다. *****\n");
    char name[100];

    printf("첫번째 선수 이름>> ");
    scanf("%s", name);
    getchar();
    player[0] = Player(name);

    printf("두번째 선수 이름>> ");
    scanf("%s", name);
    getchar();
    player[1] = Player(name);
}

void GamblingGame::play() {
    int i = 0;
    while (!isGameEnd) {
        printf("%s: <Enter>", player[i % 2].getName());
        getchar();
        if (player[i % 2].playGambling()) {
            isGameEnd = true;
            printf("\t%s님 승리!!\n", player[i % 2].getName());
        }
        else {
            printf("\t아쉽군요!\n");
        }
        i++;
    }
}

int main() {
    srand((unsigned int)time(0));
    GamblingGame game;
    game.play();
    return 0;
}
