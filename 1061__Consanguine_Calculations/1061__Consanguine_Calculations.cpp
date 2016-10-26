#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

string combine(string comb , bool r){
    string result;
    if (comb == "AA"){
        result = "A";
    }if (comb == "AB" || comb == "BA"){
        result = "AB";
    }if (comb == "BB"){
        result = "B";
    }if (comb == "OO"){
        result = "O";
    }if (comb == "OA" || comb == "AO"){
        result = "A";
    }if (comb == "BO" || comb == "OB"){
        result = "B";
    }
    if (r) result += "+";
    else result += "-";
    return result;
}


set <string> calc (string father , string mother){



    vector <char> allel_father;
    bool rh_father;
    for(int i = 0 ; i < father.size() ; i++){
        if (father[i] == 'A') allel_father.push_back('A');
        if (father[i] == 'B') allel_father.push_back('B');
        if (father[i] == 'O') allel_father.push_back('O');
        if (father[i] == '-') rh_father = false;
        if (father[i] == '+') rh_father = true;
    }
    if (father.size() <= 2){
        allel_father.push_back('O');
    }

    vector <char> allel_mother;
    bool rh_mother;
    for(int i = 0 ; i < mother.size() ; i++){
        if (mother[i] == 'A') allel_mother.push_back('A');
        if (mother[i] == 'B') allel_mother.push_back('B');
        if (mother[i] == 'O') allel_mother.push_back('O');
        if (mother[i] == '-') rh_mother = false;
        if (mother[i] == '+') rh_mother = true;
    }
    if (mother.size() <= 2){
        allel_mother.push_back('O');
    }

    set <string> possible;
    for (int i = 0 ; i < allel_father.size() ; i++){
        for (int j = 0 ; j < allel_mother.size() ; j++){
            string temp; temp += allel_father[i] ; temp += allel_mother[j];
            possible.insert(combine(temp , rh_father));
            possible.insert(combine(temp , rh_mother));
            possible.insert(combine(temp , false));
            possible.insert(combine(temp , false));
        }
    }
    return possible;
}

int main (){
    map <string , int > index;
    map <int , string> value;

    index ["O-"] = 0;
    index ["O+"] = 1;
    index ["A-"] = 2;
    index ["A+"] = 3;
    index ["B-"] = 4;
    index ["B+"] = 5;
    index ["AB-"] = 6;
    index ["AB+"] = 7;

    value [0] = "O-";
    value [1] = "O+";
    value [2] = "A-";
    value [3] = "A+";
    value [4] = "B-";
    value [5] = "B+";
    value [6] = "AB-";
    value [7] = "AB+";

    vector <vector <set <string> > > possibities(8 , vector <set <string> > (8 , set <string> ()));

    for (int i = 0 ; i < 8 ; i++){
        for (int j = 0 ; j < 8 ; j++){
            possibities[i][j] = calc(value[i],value[j]);
        }
    }


    string f , m , c;
    int case_no = 1;
    while (cin >> f >> m >> c){

        if (f == "E") return 0;
        set <string> result;
        if (c == "?"){
            result = possibities[index[f]][index[m]];
        }
        if (f == "?"){
            for (int i = 0 ; i < 8 ; i++){

                if (possibities[i][index[m]].find(c) != possibities[i][index[m]].end()){
                    result.insert(value[i]);
                }
            }
        }
        if (m == "?"){
            for (int j = 0 ; j < 8 ; j++){

                if (possibities[index[f]][j].find(c) != possibities[index[f]][j].end()){
                    result.insert(value[j]);
                }
            }
        }
        string toshow;
        if (result.size() == 0){
            toshow = "IMPOSSIBLE";
        } else if (result.size() == 1){
            toshow = *result.begin();
        } else {
            toshow = "{";
            int i = 0;
            for (set <string> :: iterator it = result.begin() ; it != result.end() ; it++ ,i++){
                if (i != 0) toshow += ", ";
                toshow += *it;
                if (i == result.size() - 1) toshow += "}";

            }
        }
        cout << "Case "  << case_no << ": "; case_no++;
        if (f == "?") cout << toshow <<  " " << m <<  " " << c << endl;
        if (m == "?") cout << f <<  " " << toshow <<  " " << c << endl;
        if (c == "?") cout << f <<  " " << m <<  " " << toshow << endl;
    }
    return 0;
}
