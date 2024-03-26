#include <iostream>
#include <string> 


enum BlockColor {
    WhiteBlock = 1,
    RedBlock = 2,
    GreenBlock = 4,
    YellowBlock = 8,
    CyanBlock = 16,
    MagentaBlock = 32,
    ExitProgram = 64
};


void drawBlock(BlockColor color) {
    switch (color) {
    case WhiteBlock:
        std::cout << "\x1b[47m  \x1b[0m";
        break;
    case RedBlock:
        std::cout << "\x1b[41m  \x1b[0m";
        break;
    case GreenBlock:
        std::cout << "\x1b[42m  \x1b[0m";
        break;
    case YellowBlock:
        std::cout << "\x1b[43m  \x1b[0m";
        break;
    case CyanBlock:
        std::cout << "\x1b[46m  \x1b[0m";
        break;
    case MagentaBlock:
        std::cout << "\x1b[45m  \x1b[0m";
        break;
    default:
        std::cout << "  ";
        break;
    }
}

int main() {
    std::cout << "화면에 그림을 그리는 프로그램입니다." << std::endl;
    std::cout << "학번: 202327038" << std::endl;
    std::cout << "이름: 김도현" << std::endl;
    std::cout << std::endl;

    std::string input;

    do {
        std::cout << "화면에 그릴 물체코드를 입력하세요: ";
        std::cin >> input;


        int blockToDraw = std::stoi(input);


        drawBlock(static_cast<BlockColor>(blockToDraw));
        std::cout << std::endl;

    } while (std::stoi(input) != ExitProgram);

    return 0;
}
