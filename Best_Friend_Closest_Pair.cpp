#include <bits/stdc++.h>
using namespace std;

int x;
int n;
vector<pair<double,double>> vec,tempvec;

void init(){
    tempvec.clear();
    vec.assign(n,{0,0});
}

double distance(pair<double, double> a, pair<double, double> b){
    return sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2));
}

bool compareX(pair<double, double> a, pair<double, double> b){
    return a.first < b.first;
}

bool compareY(pair<double, double> a, pair<double, double> b){
    return a.second < b.second;
}

double answer(int L, int R){
    if(L == R){
        return 1e18;
    }
    int middle = (L+R)/2;
    double middleValue = vec[middle].first;
    double tempMin = min(answer(L, middle), answer(middle+1, R));

    sort(vec.begin()+L, vec.begin()+R+1, compareY);
    
    tempvec.clear();
    for(int i=L; i<=R; i++){
        if(abs(vec[i].first - middleValue) <= tempMin){
            tempvec.push_back(vec[i]);
        }
    }
    int size = tempvec.size();
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(abs(tempvec[i].second - tempvec[j].second) > tempMin){
                break;
            }
            tempMin = min(tempMin, distance(tempvec[i], tempvec[j]));
        }
    }
    return tempMin;
}

int main(){
    cin >> x;
    while(x>0){
        cin >> n;
        init();
        for(int i=0; i<n; i++){
            cin>>vec[i].first>>vec[i].second;
        }
        sort(vec.begin() ,vec.end() ,compareX);
        double ans = answer(0,n-1);
        cout<<ans<<endl;
        x--;
    }
}