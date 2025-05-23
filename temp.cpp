#include<bits/stdc++.h>

using namespace std;
class Meeting {
public:
    int start;
    int end;
    int pos;

    Meeting(int s, int e, int p) : start(s), end(e), pos(p) {}
};
static bool camparator(const Meeting &m1,const Meeting &m2){
    if(m1.end<m2.end) return true;
    else if(m2.end<m1.end) return false;
    else if(m1.pos<m2.pos) return true;
    return false;
}

vector<int> Nmeeting(int *start, int *end, int n){
    vector<int > ans;
    
    vector<Meeting> meeting;
    for (int i = 0; i < n; i++)
    {
        meeting.push_back(Meeting(start[i],end[i],i+1));
    }

    sort(meeting.begin(),meeting.end(),camparator);
    int Prev_End_time = meeting[0].end;
    ans.push_back(meeting[0].pos);

    for (int i = 1; i < n; i++)
    {
        if(meeting[i].start>Prev_End_time){
            ans.push_back(meeting[i].pos);
            Prev_End_time = meeting[i].end;
        }
    }
    return ans;
}
int main(){
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};
    vector<int> arr = Nmeeting(start, end, n);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}