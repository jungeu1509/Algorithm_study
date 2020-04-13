//no.16236 (https://www.acmicpc.net/problem/16236)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define max_int 21//max of map value
#define max_val 40

using namespace std;

/*
 시간 복잡도: O(n^4)
 공간 복잡도: O(n^2)
 사용한 알고리즘: BFS(완전 탐색)
 BFS를 사용한 이유는 다음과 같습니다.
 1. 최단 경로를 찾기 위함입니다.
 2. BFS는 모든 간선의 가중치가 1일때 최단경로를 찾아줍니다.
 3. BFS의 시간 복잡도: 1) 인접리스트틀 사용한 경우 O(v+e), 2) 인접행렬을 사용한 경우(v^2)

 이 문제에서 그래프를 저장하는 자료구조는 2차원 배열..인접리스트도, 인접행렬도 아닌
 정점의 수 n^2 + 간선의 수 4*n^2 = O(5n^2), 상수 생략 O(n^2)
 사용한 자료구조: 2차원 배열, 큐
 */

const int dx[4]={0, 0, 1, -1};//up, down, right, left
const int dy[4]={-1, 1, 0, 0};
struct info{int x, y;};
//pair <int, int> info;
/*상어 또는 물고의 좌표(x, y)를 저장할 구초제 정의
가장 위, 가장 왼쪽 비교가 들어가기 때문에
pair를 사용해도 좋습니다. (pair는 비교를 해주기 때문입니다.)*/

int n; // to input
int a[max_int][max_int]; //map information
int check[max_int][max_int]; //to save move distance
int shark_x, shark_y;
int eat_cnt;
int shark_size = 2;
int min_dist;
int min_x, min_y;
int result;

//init(because of BFS)
void init_check(){
  min_dist = max_val;
  min_x = max_int;
  min_y = max_int;
  for(int i=1; i<=n; i++){//init map
    for(int j=1; j<=n; j++){
      check[i][j] = -1;
    }
  }
}

//do BFS
void bfs(int x, int y){
  queue<info> q;//define queue for use BFS
  check[x][y] = 0;// shark point
  q.push({x, y});

  while(!q.empty()){
    info cur = q.front();
    q.pop();
    int x = cur.x;
    int y = cur.y;

    for(int i=0; i<4; i++){
      int nx = x + dx[i]; //next x
      int ny = y + dy[i]; //next y

      //out of range on map
      if(nx < 1 || nx > n || ny < 1 ||ny > n ) continue;
      //skip(1. already pass 2. bigger size than shark)
      if(check[nx][ny] != -1 || a[nx][ny] > shark_size) continue;

      check[nx][ny] = check[x][y] + 1;//move point check
      if(a[nx][ny] != 0 && a[nx][ny] < shark_size){//if shark can eat fish

        /*아래 부분은 pair의 비교, 객체의 연산자 오버로딩을 통한 비교로
         더 간단하게 작성가능*/
        if(min_dist > check[nx][ny]){//check distance min
          min_x = nx;
          min_y = ny;
          min_dist = check[nx][ny];
        }
        else if(min_dist == check[nx][ny]){//if distance same firstly go upper, secondly go lefter
          if(min_x == nx){
            if(min_y > ny){
              min_x = nx;
              min_y = ny;
            }
          }
          else if(min_x > nx){
            min_x = nx;
            min_y = ny;
          }
        }
      }
      q.push({nx, ny});
    }
  }
}

int main()
{
  cin>>n;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin>>a[i][j];
      if(a[i][j]==9){ // if shark
        shark_x=i;
        shark_y=j;
        a[i][j]=0;
      }
    }
  }

  while(1)
  {
    init_check();
    bfs(shark_x, shark_y);// find eatable fish

    if(min_x != max_int && min_y != max_int){ // if find eatable fish
      result += check[min_x][min_y]; // sum move time
      eat_cnt++;

      if(eat_cnt == shark_size){//If the number of fish eaten by the shark is the same size of the shark
        shark_size++;
        eat_cnt = 0;
      }
      a[min_x][min_y]=0;//clean fish location

      shark_x = min_x;
      shark_y = min_y;//move shark
    }
    else{break;}//can't find eatable fish
  }
  return 0;
}
