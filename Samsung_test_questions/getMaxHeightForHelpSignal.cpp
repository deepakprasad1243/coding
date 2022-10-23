#include <iostream>
using namespace std;

int W[20], L[20], H[20];
bool visited[20];

int max(int &a, int &b){
    if(a > b) return a;
    return b;
}

int getMaxHeight(int topX, int topY, int N) {
    int height = 0;
    for(int i = 0; i< N; i++) {
        if(!visited[i]){
            visited[i] = true;

            if((W[i] <= topX && L[i] <= topY) || (W[i] <= topY && L[i] <= topX)) {
                height = max(height, H[i] + getMaxHeight(W[i], L[i], N));
            }

            if((W[i] <= topX && H[i] <= topY) || (W[i] <= topY && H[i] <= topX)) {
                height = max(height, L[i] + getMaxHeight(W[i], H[i], N));
            }

            if((L[i] <= topX && H[i] <= topY) || (L[i] <= topY && H[i] <= topX)) {
                height = max(height, W[i] + getMaxHeight(L[i], H[i], N));
            }

            visited[i] = false;
        }
    }

    return height;
}

int main(){

    int T;
    cin >> T;

    for(int i = 1; i<=T; i++) {

        int N; //no. of boxes
        cin >> N;
        
        for(int j = 0; j<N; j++){
            cin >> W[j] >> L[j] >> H[j];
        }

        int ans = getMaxHeight(10001, 10001, N);
        cout << "#"<<i << " " << ans << endl;
    }
	
	return 0;
}
