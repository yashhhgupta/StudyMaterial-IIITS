#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<string> &v1, vector<string> &v2)
{
    int id1 = stoi(v1[1]), id2 = stoi(v2[1]);
    int offset1 = stoi(v1[2]), offset2 = stoi(v2[2]);
    if (id1 != id2)
    {
        return id1 < id2;
    }
    return offset1 < offset2;
}
int main()
{

    ifstream source;
    source.open("frag_record.txt");
    vector<vector<string>> fragment;
    string line;
    while (getline(source, line))
    {
        vector<string> add;
        stringstream split(line);
        string word;
        while (split >> word)
        {
            add.push_back(word);
        }
        fragment.push_back(add);
    }

    sort(fragment.begin(), fragment.end(), cmp);

    for (int i = 0; i < fragment.size();)
    {
        string curr_head = fragment[i][1];
        if (((i + 1) < fragment.size()) && fragment[i][0] == fragment[i + 1][0] && fragment[i][1] == fragment[i + 1][1] && fragment[i][2] == fragment[i + 1][2] && fragment[i][3] == fragment[i + 1][3] && fragment[i][4] == fragment[i + 1][4])
        {
            cout << fragment[i][0] << " " << curr_head << " Duplicate fragment" << endl;
            while (i < fragment.size() && fragment[i][1] == curr_head)
            {
                i++;
            }
            continue;
        }
        if (fragment[i][2] != "0")
        {
            cout << fragment[i][0] << " " << curr_head << " Missing fragment" << endl;
            while (i < fragment.size() && fragment[i][1] == curr_head)
            {
                i++;
            }
            continue;
        }
        if (fragment[i][2] == "0" && fragment[i][3] == "0")
        {
            cout << fragment[i][0] << " " << curr_head << " " << stoi(fragment[i][4]) + 20 << endl;
            i++;
            continue;
        }
        int length_datagram = stoi(fragment[i][4]);
        bool check = false;
        i++;
        while ((i + 1) < fragment.size() && curr_head == fragment[i][1])
        {
            if (fragment[i][3] == "1")
            {
                int offset = stoi(fragment[i][2]) * 8;
                if (length_datagram != offset)
                {
                    check = true;
                    cout << fragment[i][0] << " " << curr_head << " Mismatch fragment" << endl;
                }
                length_datagram += stoi(fragment[i][4]);
            }
            else
            {
                length_datagram += stoi(fragment[i][4]);
                check = true;
                cout << fragment[i][0] << " " << curr_head << " " << length_datagram + 20 << endl;
            }
            i++;
        }
        if (check == false)
        {
            cout << fragment[i][0] << " " << fragment[i][1] << " Missing fragment" << endl;
        }
    }

    return 0;
}