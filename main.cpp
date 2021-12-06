#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

void writeSignalsToFile(vector<double> t, const vector<vector<double>> & f,const string & filename){
    ofstream ofs{filename};
    if(ofs) {
        for (auto i = 0; i < t.size(); i++) {
            ofs << t[i];
            for (auto e: f) {
                ofs << ", " << e[i];
            }
            ofs   << endl;
        }
    }else{
        cout<<"Warning: did not open file"<<endl;
    }
    ofs.close();
}



int main() {
    vector<double> t={0 ,.01,.02,.03,.04,.05};// you will need to edit all of these to use your functions
    vector<double> f(t.size());
    vector<double> f1(t.size());
    vector<double> f2(t.size());
    vector<double> f3(t.size());
    vector<double> f4(t.size());
    vector<double> f5(t.size());
    vector<double> f6(t.size());
    vector<double> f7(t.size());
    vector<double> f8(t.size());
    vector<double> f9(t.size());
    vector<double> f10(t.size());
    for(auto i = 0; i < t.size();i++){
        f[i]=cos(i);
        f1[i]=sin(i);
    }
    // This function just prints your data to a comma separated value file
   auto data= {t,f,f1,f2,f3,f4,f5,f6,f7,f8,f8,f10};// you can add functions here

    writeSignalsToFile(t,data,"testing.csv");
    // you can check the output in excel

}
