#include <iostream>
#include <algorithm>
using namespace std;

// variables
int N, M;    // 문제에서 N <=4인데 예제에서는 (5,5)로 주는게 있음
int board[4][500];

struct data {
    int y, x;
};

data tetromino[19][4] = {
    {{0,0}, {1,0}, {2,0}, {3,0}},
    {{0,0}, {0,1}, {0,2}, {0,3}},
    
    {{0,0}, {0,1}, {1,1}, {1,0}},
    
    {{0,0}, {1,0}, {2,0}, {2,1}},
    {{0,0}, {0,1}, {0,2}, {-1,2}},
    {{0,0}, {0,1}, {1,1}, {2,1}},
    {{0,0}, {1,0}, {0,1}, {0,2}},
    {{0,0}, {0,1}, {-1,1}, {-2,1}},
    {{0,0}, {1,0}, {1,1}, {1,2}},
    {{0,0}, {0,1}, {1,0}, {2,0}},
    {{0,0}, {0,1}, {0,2}, {1,2}},
    
    {{0,0}, {1,0}, {1,1}, {2,1}},
    {{0,0}, {0,1}, {-1,1}, {-1,2}},
    {{0,0}, {1,0}, {0,1}, {-1,1}},
    {{0,0}, {0,1}, {1,1}, {1,2}},
    
    {{0,0}, {0,1}, {-1,1}, {0,2}},
    {{0,0}, {0,1}, {-1,1}, {1,1}},
    {{0,0}, {0,1}, {0,2}, {1,1}},
    {{0,0}, {1,0}, {2,0}, {1,1}},
};

// functions
// 총 19개의 테트로미노에 대해 가장 큰 점수를 리턴
// 보드의 범위를 벗어나면 계산을 생략함
int score(int y, int x)
{
    int ret = 0;
    
    for(int i = 0; i < 19; i++){
        bool canPut = true;
        int sum = 0;
        for(int j = 0; j < 4; j++) {
            int target_y = y+tetromino[i][j].y;
            int target_x = x+tetromino[i][j].x;
            // validation check
            if( !((0<= target_y && target_y < N) && (0<= target_x && target_x < M)) ){
                canPut = false;
                break;
            }
            sum += board[target_y][target_x];
                
        }
        // 테트로미노를 둘 수 있을 경우만 계산
        if(canPut)
            ret = max(ret, sum);
    }
    return ret;
}
int main()
{
    // input
    cin >> N >> M;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    int ret = 0;
    // algorithm
    // 총 19개의 테트로미노에 대해 전부 탐색함
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            ret = max(ret, score(i, j));
        }
    }
    cout << ret << endl;
}
