#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        vector<Interval> sort_intervals;
        intervals.push_back(newInterval);
        if(intervals.size()==0)
            return result;
        int size = 0;
        for(int i=0;i<intervals.size();i++){
            int start = intervals[i].start;
            int l=0, r=sort_intervals.size()-1;
            int m;
            while(l<=r){
                m = (l+r)/2;
                if(sort_intervals[m].start<=start)
                    l = m + 1;
                if(sort_intervals[m].start>start)
                    r = m - 1;
            }
            sort_intervals.insert(sort_intervals.begin()+l,intervals[i]);
        }
        struct Interval *in1;
        in1 = new Interval(sort_intervals[0].start,sort_intervals[0].end);
        for(int i=1;i<sort_intervals.size();i++){
            //cout<<sort_intervals[i].start<<endl;
            if(in1->end>=sort_intervals[i].start){
                if(sort_intervals[i].end > in1->end)
                    in1->end = sort_intervals[i].end;
            }
            else{
                result.push_back(*in1);
                in1 = new Interval(sort_intervals[i].start,sort_intervals[i].end);
            }
        }
        result.push_back(*in1);
//        for(int i=0;i<result.size();i++)
//            cout<<result[i].start<<","<<result[i].end<<endl;
        return result;
    }
};
//
int main(){
    Solution s;
    ifstream fin("input.txt");
    vector<Interval> input;
    int a,b;
    while(fin>>a>>b){
        Interval i1(a,b);
        input.push_back(i1);
    }
    cout<<"read over"<<endl;
    Interval newInterval(2, 5);
    s.insert(input, newInterval);
}
